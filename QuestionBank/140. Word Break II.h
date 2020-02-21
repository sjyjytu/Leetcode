#include <string>
#include <vector>

using namespace std;

//1.19 9:12-9:48
//Runtime: 20 ms, faster than 52.06% of C++ online submissions for Word Break II.
//Memory Usage: 12.1 MB, less than 90.91 % of C++ online submissions for Word Break II.
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int length = s.size();
		int num = wordDict.size();
		vector<vector<int>> dp(length + 1, vector<int>(num, -1));
		for (int j = 0; j < num; j++)
		{
			dp[0][j] = 0;
		}
		for (int i = 1; i < length + 1; i++)
		{
			for (int j = 0; j < num; j++)
			{
				string tmp = wordDict[j];
				int tmpSize = wordDict[j].size();
				if (tmpSize <= i && s.substr(i - tmpSize, tmpSize) == tmp)
				{
					for (int k = 0; k < num; k++)
					{
						if (dp[i - tmpSize][k] >= 0)
						{
							dp[i][j] = j;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < length+1; i++)
		{
			for (int j = 0; j < num; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		//»ØËÝ
		vector<string> result;
		searchBack(dp, wordDict, length, "", num, result);
		return result;
	}

	void searchBack(vector<vector<int>>& dp, vector<string>& wordDict, 
		int begin, string pre, int num, vector<string> &result)
	{
		if (begin > 0)
		{
			for (int j = 0; j < num; j++)
			{
				if (dp[begin][j] >= 0)
				{
					searchBack(dp, wordDict, begin - wordDict[j].size(), wordDict[j] + " " + pre, num, result);
				}
			}
		}
		else
		{
			pre.pop_back();
			result.push_back(pre);
		}
	}
};