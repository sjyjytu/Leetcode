#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size();
		if (row==0)
		{
			return 0;
		}
		int col = obstacleGrid[0].size();
		vector<vector<long>>dp(row, vector<long>(col, 0));
		if (!obstacleGrid[0][0])
		{
			dp[0][0] = 1;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				//当前有石头
				if (obstacleGrid[i][j])
				{
					dp[i][j] = 0;
				}
				else
				{
					if (i-1>=0)
					{
						dp[i][j] += dp[i - 1][j];
					}
					if (j-1>=0)
					{
						dp[i][j] += dp[i][j - 1];
					}
				}
			}
		}
		return dp[row - 1][col - 1];
	}
};