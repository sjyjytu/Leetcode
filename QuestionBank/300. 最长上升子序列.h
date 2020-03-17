#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0)
			return 0;
		vector<int> dp(n, 1);
		for (int i = 0; i < n; i++)
		{
			int cur_max = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
				{
					cur_max = max(cur_max, dp[j] + 1);
				}
			}
			dp[i] = cur_max;
		}
		int global_max = 1;
		for (int i = 0; i < n; i++)
		{
			if (dp[i] > global_max)
			{
				global_max = dp[i];
			}
		}
		return global_max;
	}
};