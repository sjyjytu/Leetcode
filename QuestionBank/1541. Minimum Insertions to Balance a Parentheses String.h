#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c=='('&&!stk.empty()&&stk.top()==')')
            {
                result++;
                stk.pop();
                if (!stk.empty()&&stk.top()=='(')
                {
                    stk.pop();
                }
                else
                {
                    result++;
                }
                stk.push(c);
            }
            else if (c==')')
            {
                if (!stk.empty() && stk.top() == ')')
                {
                    stk.pop();
                    if (!stk.empty() && stk.top() == '(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        result++;
                    }
                }
                else
                {
                    stk.push(c);
                }
            }
            else
            {
                stk.push(c);
            }
        }
        if (!stk.empty())
        {
            if (stk.top()==')')
            {
                stk.pop();
                if (stk.empty())
                {
                    result += 2;
                }
                else
                {
                    stk.pop();
                    result += 1;
                }
            }
            while (!stk.empty())
            {
                stk.pop();
                result += 2;
            }
        }
        return result;
    }

    //other's beautiful solution
    int minInsertions2(string t) {

        int top = 0, ans = 0;
        int n = t.length();
        for (int i = 0; i < n; i++) {
            char c = t[i];
            if (c == '(')
                top++;
            else {
                if (i + 1 < n && t[i + 1] == ')') i++;
                else ans++;

                if (top == 0) ans++;
                else top--;
            }
        }

        return ans + 2 * top;
    }
};