#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//2020 2-22 8:00- 10:14
class Solution {
public:
	int stoneGameII(vector<int>& piles) {
		int sum = 0;
		int n = piles.size();
		for (int i = 0; i < n; i++)
		{
			sum += piles[i];
		}
		return (dfs(piles, n, 0, 1) + sum) / 2;
	}

	//超时，改成动态规划
	int dfs(vector<int>& piles, int n, int index, int M)
	{
		if (index + 2*M >= n)
		{
			int sum = 0;
			for (int i = index; i < n; i++)
			{
				sum += piles[i];
			}
			return sum;
		}

		int sum = piles[index];
		int result = sum - dfs(piles, n, index + 1, max(1, M));
		for (int x = 1; x < 2*M && index + x < piles.size(); x++)
		{
			sum += piles[index + x];
			int f = sum - dfs(piles, n, index + x + 1, max(x + 1, M));
			if (f > result)
			{
				result = f;
			}
		}
		return result;
	}

	//Runtime: 4 ms, faster than 90.66% of C++ online submissions for Stone Game II.
	//Memory Usage : 9.2 MB, less than 100.00 % of C++ online submissions for Stone Game II.
	int stoneGameII2(vector<int>& piles) {
		int n = piles.size();
		int maxM = 100;
		vector<vector<int>> dp(n, vector<int>(maxM+1, 0));
		vector<int> sumPiles(n+1, 0);
		for (int i = n-1; i >= 0; i--)
		{
			sumPiles[i] = piles[i] + sumPiles[i + 1];
		}
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 1; j <= maxM; j++)
			{
				if (i + 2 * j >= n)
				{
					dp[i][j] = sumPiles[i];
				}
				else
				{
					int result = -1e7;
					for (int x = 0; x < 2*j; x++)
					{
						result = max(result, sumPiles[i] - sumPiles[i + x + 1] - dp[i + x + 1][max(x + 1, j)]);
					}
					dp[i][j] = result;
				}
			}
		}
		return (dp[0][1] + sumPiles[0]) / 2;
	}
};