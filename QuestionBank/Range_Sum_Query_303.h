#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//12.21 11：57 水一道简单的dp 5% 6% 先绿了再优化
class NumArray {
private:
	vector<vector<int>> dp;
public:
	NumArray(vector<int>& nums) {
		int n = nums.size();
		dp = vector<vector<int>>(n);
		for (int i = 0; i < n; i++)
		{
			dp[i] = vector<int>(n);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				dp[i][j] = nums[j];
				if (j - 1>=0)
				{
					dp[i][j] += dp[i][j - 1];
				}
			}
		}
	}

	int sumRange(int i, int j) {
		return dp[i][j];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */