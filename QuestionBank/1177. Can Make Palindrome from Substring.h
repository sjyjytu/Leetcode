#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
		int n = s.size();
		vector<vector<int>>dp(n+1, vector<int>(26, 0));
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				dp[i][j] = dp[i - 1][j];
			}
			dp[i][s[i - 1] - 'a'] ++;
		}
		vector<bool> result(queries.size(), false);
		for (int i = 0; i < queries.size(); i++)
		{
			vector<int> cur = queries[i];
			int diffCount = 0;
			for (int j = 0; j < 26; j++)
			{
				int charDis = dp[cur[1] + 1][j] - dp[cur[0]][j];
				if (charDis % 2 == 1)
				{
					diffCount++;
				}
				
			}
			//如果长度为奇数，可以容忍一个不一样
			if ((cur[1] - cur[0] + 1) % 2 == 1)
			{
				diffCount--;
			}
			if (cur[2]*2 >= diffCount)
			{
				result[i] = true;
			}
		}
		return result;
	}
};