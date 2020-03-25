#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//������ѧ�Ľⷨ����Ȼ˫��
	//˼·���ǣ������ǳɻ����ֱ��ö�̬�滮�����0��n-2�ʹ�1��n-1�����ֵ�����ض���֮��Ľϴ�ֵ
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
		//ȷ����������nums��С����3.
		int n = nums.size();
		//ÿ����Ԫ���У���һ��Ԫ�ش������ֵ���ڶ���Ԫ�ش���õ������ֵ����������ǰԪ�أ���û��͵��һ�ң�
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