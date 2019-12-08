#include <vector>

using namespace std;

class Solution {
public:
	//递归搜索，测试超内存了
	bool canJump1(vector<int>& nums) {
		vector<int> impossible(nums.size());
		return curIndexCanJump(nums, impossible, 0);
	}

	bool curIndexCanJump(vector<int> nums, vector<int> &impossible, int curIndex)
	{
		if (curIndex >= nums.size()-1)
		{
			return true;
		}
		for (int i = 0; i < nums[curIndex]; i++)
		{
			int nextIndex = curIndex + i + 1;
			if (impossible[nextIndex] != 1)
			{
				if (curIndexCanJump(nums, impossible, nextIndex))
				{
					return true;
				}
				else
				{
					impossible[nextIndex] = 1;
				}
			}
		}
		return false;
	}

	//转化为从0出发，最远能到哪，复杂度O（n^2），时间只打败了5%的玩家，太垃圾了
	bool canJump2(vector<int>& nums) {
		vector<int> canGet(nums.size());
		if (nums.size() > 0)
		{
			canGet[0] = 1;
		}
		else
		{
			return true;
		}
		if (nums.size()==1)
		{
			return true;
		}
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (canGet[i] == 1)
			{
				for (int j = 1; j < nums[i] + 1; j++)
				{
					if (i + j >= nums.size() - 1)
					{
						return true;
					}
					canGet[i + j] = 1;
				}
			}
		}
		return false;
	}

	//哎，还是想不出来，结果网上一搜，简单的一逼，我还是太菜了
	//一个很重要的结论：如果一个点可以到达，那他之前的所有点都可以到达，所以只要看最远能到多远
	bool canJump(vector<int>& nums) {
		int max = 0;
		//int n = nums.size();  //神奇，如果这样写的话，内存会少用一点，但是运行时间却慢了8ms
		for (int i = 0; i < nums.size() && i <= max; i++)
		{
			if (i+nums[i]>=max)
			{
				max = i + nums[i];
			}
		}
		return max >= nums.size() - 1;
	}
};