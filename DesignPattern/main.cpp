#include <iostream>
//#include "Singleton.h"
//#include "SimpleFactory.h"
//#include "Factory.h"
//#include "AbstractFactory.h"
//#include "Builder.h"
//#include "ProtoType.h"
//#include "ChainOfResponsibility.h"
#include "Command.h"
using namespace std;


int main()
{
	////����ģʽ
	//Singleton* p1 = Singleton::getSingleton();
	//Singleton* p2 = p1->getSingleton();
	//cout << p1 << " " << p2 << endl;

	////�򵥹���
	//SimpleFactory simpleFactory;
	//for (int i = 0; i < 3; i++)
	//{
	//	simpleFactory.createProduct(i)->aboutMe();
	//}
	
//	//��������
//	Factory1 factory1;
//	Factory2 factory2;
//	factory1.doSomething();
//	factory2.doSomething();

	////���󹤳�
	//Factory1 factory1;
	//Factory2 factory2;
	//factory1.doSomething();
	//factory2.doSomething();

	////������Builder
	////�����ò��ֹ��������ͨ��������
	//Builder builder;
	//for (int i = 0; i < 26; i++)
	//{
	//	builder.append('a' + i);
	//}
	//cout << builder.getResult() << endl;

	////ԭ��ģʽ
	////���Ƹ��ƹ��캯�����ô��ǿ��Զ�̬���Ҫ���ƶ���ǰ��״̬���Ҹ���Ч�����ɵ��¶��󻹿�����������
	//ProtoType* p1 = new ConcreteProtoType(3);
	//ProtoType* p2 = p1->myClone();

	////������ģʽ
	//Manager* boss = new Boss(NULL, "Big Boss");
	//Manager* m2 = new Manager2(boss, "m2");
	//Manager* m1 = new Manager1(m2, "m1");
	//m1->handleRequest("D", 300);
	//m1->handleRequest("E", 1300);
	//m1->handleRequest("F", 3300);
	//delete m1;
	//delete m2;
	//delete boss;

	//����ģʽ
	/*Receiver* receiver = new Receiver();
	Command* concreteCommand = new ConcreteCommand(receiver);
	Invoker* someone = new Invoker(concreteCommand);
	someone->call();*/
	while (true)
	{
		cout << "hah" << endl;
	}
	return 0;
}