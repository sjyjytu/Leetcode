#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
		vector<int> old_sum;
		vector<int> new_sum;
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			old_sum = new_sum;
			new_sum.clear();
			if (nums[i]==target)
			{
				res++;
				new_sum.clear();
				continue;
			}
			new_sum.push_back(nums[i]);
			for (int j = 0; j < old_sum.size(); j++)
			{
				int t = old_sum[j] + nums[i];
				if (t==target)
				{
					res++;
					new_sum.clear();
					break;
				}
				new_sum.push_back(t);
			}
		}
		return res;
    }

	int maxNonOverlapping(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> sum(n,vector<int>());
		int res = 0;
		bool last_ok = true;
		for (int i = 0; i < n; i++)
		{
			if (nums[i]==target)
			{
				res++;
				last_ok = true;
				continue;
			}
			else
			{
				sum[i].push_back(nums[i]);
				if (!last_ok)
				{
					for (int j = 0; j < sum[i-1].size(); j++)
					{
						int t = nums[i] + sum[i - 1][j];
						if (t==target)
						{
							res++;
							last_ok = true;
							break;
						}
						sum[i].push_back(t);
					}
				}
				else
				{
					last_ok = false;
				}
			}
		}
		return res;
	}

	int maxNonOverlapping(vector<int>& nums, int target) {
		int n = nums.size();
		unordered_set<int> s;
		int res = 0;
		int sum = 0;
		s.insert(0);
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (s.find(sum-target)!=s.end())
			{
				res++;
				s.clear();
				s.insert(0);
				sum = 0;
			}
			else
			{
				s.insert(sum);
			}
		}
		return res;
	}
};