#include <string>
#include <vector>

using namespace std;

//1.18 9:40-10:25 要开始学习了！
//Runtime: 4 ms, faster than 94.76% of C++ online submissions for Word Break.
//Memory Usage: 9 MB, less than 88.68 % of C++ online submissions for Word Break.
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int length = s.size();
		int num = wordDict.size();
		vector<vector<bool>> dp(length+1, vector<bool>(num, 0));
		for (int j = 0; j < num; j++)
		{
			dp[0][j] = 1;
		}
		for (int i = 1; i < length+1; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (j > 0)
				{
					dp[i][j] = dp[i][j - 1];
				}
				string tmp = wordDict[j];
				int tmpSize = wordDict[j].size();
				if (tmpSize <=i&&s.substr(i- tmpSize,tmpSize)== tmp)
				{
					for (int k = 0; k < num; k++)
					{
						if (dp[i- tmpSize][k])
						{
							dp[i][j] = 1;
							break;
						}
					}
				}
			}
		}

		bool result = false;
		for (int j = 0; j < num; j++)
		{
			if (dp[length][j])
			{
				//return true;
				result = true;
				break;
			}
		}
		return result;
	}

	//再来优化一下空间
	//Runtime: 4 ms, faster than 94.76 % of C++ online submissions for Word Break.
	//Memory Usage: 8.7 MB, less than 100.00 % of C++ online submissions for Word Break.
	bool wordBreak2(string s, vector<string>& wordDict) {
		int length = s.size();
		int num = wordDict.size();
		vector<bool>dp(length + 1, 0);
		dp[0] = 1;
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
						if (dp[i - tmpSize])
						{
							dp[i] = 1;
							break;
						}
					}
				}
			}
		}
		return dp[length];
	}
};