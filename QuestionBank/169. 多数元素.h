#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int candidate;
		int count;
		int index = 0;
		int n = nums.size();
		while (index < n)
		{
			candidate = nums[index++];
			count = 1;
			while (count > 0 && index < n)
			{
				if (nums[index++]==candidate)
				{
					count++;
				}
				else
				{
					count--;
				}
			}
		}
		return candidate;
	}
};