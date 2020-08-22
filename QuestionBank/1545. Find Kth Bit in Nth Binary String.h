#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
		if (k%2==1)
		{
			return (k + 1) / 2 % 2 == 0 ? '1' : '0';
		}
		else
		{
			/*int x = k / 2;
			string s = "1";
			for (int i = 3; i <= n; i++)
			{
				string tmp = "";
				bool one = true;
				tmp += '1';
				one = !one;
				for (int j = 0; j < s.size(); j++)
				{
					tmp += s[j];
					tmp += one ? '1' : '0';
					one = !one;
				}
				s = tmp;
			}
			return s[x - 1];*/
			int x = k / 2 - 1;
			while (x % 2 !=0 && n > 2)
			{
				x = (k - 1) / 2;
				n--;
			}
			if (x % 2 == 0)
			{
				return x / 2 % 2 == 0 ? '1' : '0';
			}
			else
			{
				return '1';
			}
		}
    }
};