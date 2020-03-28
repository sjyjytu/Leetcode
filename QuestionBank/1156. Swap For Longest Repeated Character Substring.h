#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int maxRepOpt1(string text) {
		int n = text.size();
		if (n==0)
		{
			return 0;
		}
		vector<int>dp(n,0);
		vector<int>segments;  //记录每一段的开始下标
		unordered_map<char, int> char2segments;  //记录某字符的段数
		dp[0] = 1;
		segments.push_back(0);
		char2segments[text[0]] = 1;
		for (int i = 1; i < n; i++)
		{
			if (text[i]==text[i-1])
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				dp[i] = 1;
				segments.push_back(i);
				char2segments[text[i]] += 1;
			}
		}
		if (segments.size()==1)
		{
			return n;
		}
		if (segments.size()==2)
		{
			return max(dp[segments[1] - 1], dp[n - 1]);
		}
		int maxLength = -1;
		for (int i = 0; i < segments.size(); i++)
		{
			int curSegLen = i == segments.size() - 1 ? n - segments[i] : segments[i + 1] - segments[i];
			if (curSegLen > maxLength)
			{
				maxLength = curSegLen;
			}
			if (char2segments[text[segments[i]]] > 1 && curSegLen + 1 > maxLength)
			{
				maxLength = curSegLen + 1;
			}
			if (i+2 < segments.size() && segments[i+2] - segments[i + 1] == 1 && text[segments[i]] == text[segments[i + 2]])
			{
				int nextLen = i + 2 == segments.size() - 1 ? n - segments[i + 2] : segments[i + 3] - segments[i + 2];
				int combineLen = curSegLen + nextLen;
				//看看能不能从前面或后面找一个出来替换掉
				if (char2segments[text[segments[i]]] > 2)
				{
					combineLen++;
				}
				if (combineLen > maxLength)
				{
					maxLength = combineLen;
				}
			}
			
		}
		return maxLength;
	}
};
