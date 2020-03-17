#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		return gcd(str1, str2);
	}

	string gcd(string str1, string str2)
	{
		if (str1 == str2)
		{
			return str1;
		}
		string result;
		if (str1.size()>=str2.size())
		{
			return str1substr2(str1, str2, result) ? gcd(str2, result) : "";
		}
		else
		{
			return str1substr2(str2, str1, result) ? gcd(str1, result) : "";
		}
	}

	bool str1substr2(string str1, string str2, string &result)
	{
		for (int i = 0; i < str2.size(); i++)
		{
			if (str1[i] != str2[i])
			{
				result = "";
				return false;
			}
		}
		result = str1.substr(str2.size());
		return true;
	}
};