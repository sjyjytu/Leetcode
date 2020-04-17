#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //����Ҫ֪���ж��ٸ����ŵĿ��ܣ���֤���ظ���û���ظ�
        //���ˣ������е㸴�ӣ������õݹ��
        //solve(1+2-3*4) = 1+solve(2-3*4) + solve(1+2) - solve(3*4) +solve(1+2-3)*4
        vector<int> oIndex;  //��������±�
        oIndex.push_back(-1);  //��-1����ʼ������parseInt
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i]=='+'|| input[i] == '-'|| input[i] == '*')
            {
                oIndex.push_back(i);
            }
        }
        oIndex.push_back(input.size());  //��n������������parseInt
        vector<int> result = solve(input, oIndex, 1, oIndex.size() - 2);
        return result;
    }

    vector<int> solve(string &input, vector<int> &oIndex, int oIndexBeginIndex, int oNum)
    {
        if (oNum==0)
        {
            return { stoi(input.substr(oIndex[oIndexBeginIndex - 1] + 1, oIndex[oIndexBeginIndex])) };
        }
        if (oNum==1)
        {
            int oi = oIndex[oIndexBeginIndex];
            int num1 = myStoI(input, oIndex[oIndexBeginIndex - 1] + 1, oi);
            int num2 = myStoI(input, oi+1, oIndex[oIndexBeginIndex + 1]);
            switch (input[oi])
            {
            case '+':
                return { num1 + num2 };
            case '-':
                return { num1 - num2 };
            case '*':
                return { num1 * num2 };
            default:
                return {};
            }
        }
        else
        {
            vector<int> result;
            for (int i = 0; i < oNum; i++)
            {
                int oi = oIndex[oIndexBeginIndex + i];
                char op = input[oi];
                vector<int> num1s = solve(input, oIndex, oIndexBeginIndex, i);
                vector<int> num2s = solve(input, oIndex, oIndexBeginIndex + i + 1, oNum - i - 1);
                for (int x = 0; x < num1s.size(); x++)
                {
                    for (int y = 0; y < num2s.size(); y++)
                    {
                        if (op=='+')
                        {
                            result.push_back(num1s[x] + num2s[y]);
                        }
                        else if (op == '-')
                        {
                            result.push_back(num1s[x] - num2s[y]);
                        }
                        else if (op == '*')
                        {
                            result.push_back(num1s[x] * num2s[y]);
                        }
                    }
                }
            }
            return result;
        }
    }

    int myStoI(string& s, int bi, int ei)
    {
        int result = 0;
        for (int i = bi; i < ei; i++)
        {
            result *= 10;
            result += s[i] - '0';
        }
        return result;
    }
};