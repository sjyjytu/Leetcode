#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		if (N==0)
		{
			return 0;
		}
		vector <vector<vector<int>>> dp(N, vector<vector<int>>(m, vector<int>(n, 0)));
		int fnum = 1e9 + 7;
		for (int _i = 0; _i < m; _i++)
		{
			dp[0][_i][0] += 1;
			dp[0][_i][n-1] += 1;
		}
		for (int _i = 0; _i < n; _i++)
		{
			dp[0][0][_i] += 1;
			dp[0][m - 1][_i] += 1;
		}
		for (int _i = 1; _i < N; _i++)
		{
			for (int _j = 0; _j < m; _j++)
			{
				for (int _k = 0; _k < n; _k++)
				{
					//dp[_i]  [_j][_k]
					int i_j_k_result = 0;
					if (_j - 1 >= 0) i_j_k_result = (i_j_k_result + dp[_i - 1][_j - 1][_k]) % fnum;
					if (_j + 1 < m) i_j_k_result = (i_j_k_result + dp[_i - 1][_j + 1][_k]) % fnum;
					if (_k - 1 >= 0) i_j_k_result = (i_j_k_result + dp[_i - 1][_j][_k-1]) % fnum;
					if (_k + 1 < n) i_j_k_result = (i_j_k_result + dp[_i - 1][_j][_k+1]) % fnum;
					dp[_i][_j][_k] = i_j_k_result % fnum;
				}
			}
		}
		int result = 0;
		for (int  _i = 0; _i < N; _i++)
		{
			result = (result + dp[_i][i][j]) % fnum;
		}
		return result;
	}
};