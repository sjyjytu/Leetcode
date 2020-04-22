#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string LongStringAdd(string a, string b)
	{
		//a.size() <= b.size()
		if (a.size()>b.size())
		{
			return LongStringAdd(b, a);
		}
		int m = a.size();
		int n = b.size();
		string result = "";
		int add_bit = 0;  //½øÎ»
		for (int i = 0; i < m; i++)
		{
			char ai = a[m - i - 1];
			char bi = b[n - i - 1];
			int r = ai - '0' + bi - '0' + add_bit;
			result = char((r % 10) + '0') + result;
			add_bit = r / 10;
		}
		for (int i = m; i < n; i++)
		{
			char bi = b[n - i - 1];
			int r = bi - '0' + add_bit;
			result = char((r % 10) + '0') + result;
			add_bit = r / 10;
		}
		if (add_bit==1)
		{
			result = '1' + result;
		}
		return result;
	}
	bool solve(string s)
	{
		//1 2 3 5 8 13
		int n = s.size();
		for (int alen = 1; 2*alen < n; alen++)
		{
			for (int blen = 1; blen <= n - alen; blen++)
			{
				
				if (IsAdditiveString(s, alen, blen))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool IsAdditiveString(string &s, int alen, int blen)
	{
		string a = s.substr(0, alen);
		string b = s.substr(alen, blen);
		string result = "";
		int result_begin_index = a.size();
		bool ok = true;
		while (ok)
		{
			result_begin_index += b.size();
			result = LongStringAdd(a, b);
			for (int i = 0; i < result.size(); i++)
			{
				if (result[i] != s[result_begin_index + i])
				{
					ok = false;
					break;
				}
			}
			a = b;
			b = result;
			if (ok && result_begin_index+result.size()==s.size())
			{
				return true;
			}
		}
		return false;
	}
};
