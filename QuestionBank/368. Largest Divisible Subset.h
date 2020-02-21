#include <vector>
using namespace std;
//12:11 11:57am 20ms 98%
class Solution {
public:
	//¶¯Ì¬¹æ»®
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		if (n==0)
		{
			return vector<int>();
		}
		if (n == 1)
			return nums;
		//sort(nums.begin(), nums.end());
		quickSort(nums, 0, n-1);
		int* dp;
		int* path;
		dp = new int[n];
		path = new int[n];
		for (int i = 0; i < n; i++)
		{
			dp[i] = 0;
			path[i] = -1;
		}
		int largestIndex = 0;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (nums[i]%nums[j]==0)
				{
					int a = dp[j] + 1;
					if (a > dp[i])
					{
						dp[i] = a;
						path[i] = j;
						if (a > max)
						{
							max = a;
							largestIndex = i;
						}
					}
				}
			}
		}
		vector<int> result;
		int index = largestIndex;
		while (index >= 0)
		{
			result.push_back(nums[index]);
			index = path[index];
		}
		return result;
	}

	void quickSort(vector<int>& nums, int left, int right)
	{
		if (left < right)
		{
			int tleft = left;
			int tright = right;
			int flag = nums[tleft];
			while (tleft < tright)
			{
				while (tleft < tright && nums[tright] >= flag)
				{
					tright--;
				}
				nums[tleft] = nums[tright];
				while (tleft < tright && nums[tleft] <= flag)
				{
					tleft++;
				}
				nums[tright] = nums[tleft];
			}
			nums[tleft] = flag;
			quickSort(nums, left, tleft - 1);
			quickSort(nums, tleft + 1, right);
		}
		
	}
};
 