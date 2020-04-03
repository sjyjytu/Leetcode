#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	//利用反向中序遍历的思想，超时，dp吧
	int numTrees(int n) {
		if (n == 0 || n == 1)
		{
			return 1;
		}
		int result = 0;
		for (int left_num = 0; left_num < n; left_num++)
		{
			int right_num = n - left_num - 1;
			result += numTrees(left_num) * numTrees(right_num);
		}
		return result;
	}

	int numTrees2(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;
		for (int total_num = 2; total_num <= n; total_num++)
		{
			int cur_result = 0;
			for (int i = 0; i < total_num; i++)
			{
				cur_result += dp[i] * dp[total_num - i - 1];
			}
			dp[total_num] = cur_result;
		}
		return dp[n];
	}
};