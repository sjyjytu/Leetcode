#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

//2020 2-17 17:18
class Solution {
public:
	//Runtime: 8 ms, faster than 97.54% of C++ online submissions for Minimum Window Substring.
	//Memory Usage : 10.1 MB, less than 78.00 % of C++ online submissions for Minimum Window Substring.
	string minWindow(string s, string t) {
		vector<int> letterNeedCount(128, 0);
		for (int i = 0; i < t.size(); i++)
		{
			letterNeedCount[t[i]]++;
		}

		int cnt = 0, left = 0;
		int minLen = INT_MAX, minLeft = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (--letterNeedCount[s[i]]>=0)
			{
				cnt++;
			}
			while (cnt==t.size())
			{
				if (minLen > i - left + 1)
				{
					minLen = i - left + 1;
					minLeft = left;
				}
				if (++letterNeedCount[s[left]]>0)
				{
					cnt--;
				}
				left++;
			}
		}
		if (minLeft == -1)
		{
			return "";
		}
		return s.substr(minLeft, minLen);
	}

	//Runtime: 16 ms, faster than 71.13% of C++ online submissions for Minimum Window Substring.
	//Memory Usage: 10 MB, less than 92.00 % of C++ online submissions for Minimum Window Substring.
	string minWindow2(string s, string t) {
		unordered_map<char, int> letterNeedCount;
		for (int i = 0; i < t.size(); i++)
		{
			letterNeedCount[t[i]]++;
		}

		int cnt = 0, left = 0;
		int minLen = INT_MAX, minLeft = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (--letterNeedCount[s[i]] >= 0)
			{
				cnt++;
			}
			while (cnt == t.size())
			{
				if (minLen > i - left + 1)
				{
					minLen = i - left + 1;
					minLeft = left;
				}
				if (++letterNeedCount[s[left]] > 0)
				{
					cnt--;
				}
				left++;
			}
		}
		if (minLeft == -1)
		{
			return "";
		}
		return s.substr(minLeft, minLen);
	}
};