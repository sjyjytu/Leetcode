# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'untitled.ui'
#
# Created by: PyQt5 UI code generator 5.14.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QFileDialog
import re


class Ui_MainWindow(object):
    def __init__(self):
        self.filename = ''

    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(140, 90, 571, 351))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.pushButton = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.pushButton.setObjectName("pushButton")
        self.gridLayout.addWidget(self.pushButton, 0, 3, 1, 1)
        self.label_2 = QtWidgets.QLabel(self.gridLayoutWidget)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 1, 0, 1, 1)
        self.label = QtWidgets.QLabel(self.gridLayoutWidget)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        # self.textBrowser = QtWidgets.QTextBrowser(self.gridLayoutWidget)
        self.textBrowser = QtWidgets.QTextEdit(self.gridLayoutWidget)
        self.textBrowser.setObjectName("textBrowser")
        self.gridLayout.addWidget(self.textBrowser, 3, 0, 1, 4)
        self.label_3 = QtWidgets.QLabel(self.gridLayoutWidget)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 2, 0, 1, 4)
        self.lineEdit = QtWidgets.QLineEdit(self.gridLayoutWidget)
        self.lineEdit.setObjectName("lineEdit")
        self.gridLayout.addWidget(self.lineEdit, 1, 1, 1, 1)
        self.pushButton_2 = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.pushButton_2.setObjectName("pushButton_2")
        self.gridLayout.addWidget(self.pushButton_2, 1, 3, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.filename = ''
        self.bind()
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.pushButton.setText(_translate("MainWindow", "浏览"))
        self.label_2.setText(_translate("MainWindow", "请输入搜索项"))
        self.label.setText(_translate("MainWindow", "请选择要搜索的文本文件"))
        self.label_3.setText(_translate("MainWindow", "搜索结果："))
        self.pushButton_2.setText(_translate("MainWindow", "搜索"))

    def bind(self):
        self.pushButton.clicked.connect(self.openFile)
        self.pushButton_2.clicked.connect(self.search)

    def openFile(self):
        self.filename, filetype = QFileDialog.getOpenFileName(self, '选择文本文件')
        print(self.filename, filetype)

    def parse_regulation(self, reg):
        # 只支持单个布尔操作
        reg = reg.strip(' ')
        if reg.find('&&') != -1:
            words = reg.split('&&')
            return [' '.join(words)], []
        elif reg.find('||') != -1:
            words = reg.split('||')
            return words, []
        elif reg[0] == '!':
            return [], [reg[1:]]
        else:
            return [reg], []

    def find_with_rules(self, lowerline, expected):
        expected = expected.strip(' ')
        expected_words = expected.split(' ')
        states = ['', 's', 'es', 'ed', 'ing']
        regardless_state_list = [expected_words[0] + state for state in states]
        if len(expected_words) == 2:
            new_regardless_state_list = [r + ' ' + expected_words[1] + state for r in regardless_state_list for state in states]
            regardless_state_list = new_regardless_state_list
        for possible in regardless_state_list:
            for fidr in re.finditer(possible, lowerline):
                fidx = fidr.start()
                if fidx != -1 and (fidx - 1 < 0 or not lowerline[fidx - 1].isalpha()) \
                        and (fidx + len(possible) >= len(lowerline) or not lowerline[fidx + len(possible)].isalpha()):
                    return True
        return False

    def search(self):
        self.textBrowser.setText('')
        reg = self.lineEdit.text().lower()
        appear_one, cannot_appear = self.parse_regulation(reg)
        occurrences = {}
        search_result = []
        search_result_index = 1
        for ao in appear_one:
            occurrences[ao] = 0
        with open(self.filename, encoding='utf-8') as f:
            linenum = 0
            for line in f:
                linenum += 1
                ok = True
                lower_line = line.lower()
                for ca in cannot_appear:
                    if self.find_with_rules(lower_line, ca):
                        ok = False
                        break
                if ok:
                    cur_line_been_add = False
                    for ao in appear_one:
                        if self.find_with_rules(lower_line, ao):
                            occurrences[ao] += 1
                            if not cur_line_been_add:
                                cur_line_been_add = True
                                search_result.append('%i. (%i) ' % (search_result_index, linenum) + line)
                                search_result_index += 1
                    # 单个！操作
                    if len(appear_one) == 0:
                        search_result.append('%i. (%i) ' % (search_result_index, linenum) + line)
                        search_result_index += 1
        occurrences_text = []
        for k in occurrences.keys():
            occurrences_text.append('%s: %i occurrences\n' % (k, occurrences[k]))
        self.textBrowser.setPlainText(''.join(occurrences_text) + ''.join(search_result))
