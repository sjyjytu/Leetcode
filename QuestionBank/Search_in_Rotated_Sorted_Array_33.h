#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n==0)
		{
			return -1;
		}
		if (n==1)
		{
			return nums[0] == target;
		}
		int left = 0, right = n-1;
		
		if (target <= nums[right])
		{
			while (left < right)
			{
				int mid = left;
				while (nums[mid] > nums[right])
				{
					left = mid + 1;
					mid = (left + right) / 2;
				}
				if (target == nums[mid] )
				{
					return mid;
				}
				if (target > nums[mid])
				{
					//在mid和right中做二分搜索即可
					return binarySearch(nums, target, mid, right);
				}
				else
				{
					right = mid;
				}
			}
			return -1;
		}
		else// (target > nums[left])
		{
			while (left < right)
			{
				int mid = right;
				while (nums[mid] < nums[left])
				{
					right = mid - 1;
					mid = (left + right) / 2;
				}
				if (target == nums[mid])
				{
					return mid;
				}
				if (target < nums[mid])
				{
					//在left和mid中做二分搜索即可
					return binarySearch(nums, target, left, mid);
				}
				else
				{
					left = mid;
				}
			}
			return -1;
		}
	}

	int binarySearch(vector<int>& nums, int target, int left, int right)
	{
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (target == nums[mid])
				return mid;
			if (target < nums[mid])
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
		return -1;
	}
};