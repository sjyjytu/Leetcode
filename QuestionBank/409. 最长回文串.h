#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int count[58] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i] - 'A'] += 1;
		}
		int result = 0;
		bool has_use_odd = false;
		for (int i = 0; i < 58; i++)
		{
			if (count[i] > 0)
			{
				if (count[i] % 2 == 0)
				{
					result += count[i];
				}
				else if (!has_use_odd)
				{
					has_use_odd = true;
					result += count[i];
				}
				else
				{
					result += count[i] - 1;
				}
			}
		}
		return result;
	}
};