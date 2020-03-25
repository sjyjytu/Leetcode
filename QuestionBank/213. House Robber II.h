#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//充满玄学的解法，竟然双百
	//思路就是，不考虑成环，分别用动态规划计算从0到n-2和从1到n-1的最大值，返回二者之间的较大值
	int rob(vector<int>& nums) {
		int n = nums.size();
		int maxOne = 0;
		if (n<=3)
		{
			for (int i = 0; i < n; i++)
			{
				if (nums[i] > maxOne)
				{
					maxOne = nums[i];
				}
			}
			return maxOne;
		}
		return max(maxNotConsiderCircle(nums, 0, n - 2), maxNotConsiderCircle(nums, 1, n - 1));
	}

	int maxNotConsiderCircle(vector<int>& nums, int beginIndex, int endIndex)
	{
		//确保传进来的nums大小大于3.
		int n = nums.size();
		//每个子元素中，第一个元素代表最大值，第二个元素代表得到此最大值有无依靠当前元素（有没有偷这一家）
		vector<vector<int>>dp(n, vector<int>(2, 0));
		dp[beginIndex][0] = nums[beginIndex];
		dp[beginIndex][1] = 1;
		if (nums[beginIndex+1]>nums[beginIndex])
		{
			dp[beginIndex + 1][0] = nums[beginIndex + 1];
			dp[beginIndex + 1][1] = 1;
		}
		else
		{
			dp[beginIndex + 1][0] = nums[beginIndex];
			dp[beginIndex + 1][1] = 0;
		}
		for (int i = beginIndex+2; i <= endIndex; i++)
		{
			if (!dp[i-1][1])
			{
				dp[i][1] = 1;
				dp[i][0] = dp[i-1][0]+nums[i];
			}
			else
			{
				if (nums[i]+dp[i-2][0] > dp[i-1][0])
				{
					dp[i][0] = nums[i] + dp[i - 2][0];
					dp[i][1] = 1;
				}
				else
				{
					dp[i][0] = dp[i - 1][0];
					dp[i][1] = 0;
				}
			}
		}
		return dp[endIndex][0];
	}
};