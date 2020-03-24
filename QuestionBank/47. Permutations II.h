#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		unordered_map<int, int> num2count;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			num2count[nums[i]]++;
		}
		vector<int> one_result;
		permute(num2count, one_result, n);
		return result;
	}
	void permute(unordered_map<int, int>& num2count, vector<int>& one_result, int n)
	{
		if (n == one_result.size())
		{
			result.push_back(one_result);
			return;
		}
		for (auto it = num2count.begin(); it != num2count.end(); it++)
		{
			if (it->second > 0)
			{
				it->second--;
				one_result.push_back(it->first);
				permute(num2count, one_result, n);
				one_result.pop_back();
				it->second++;
			}
		}
	}
};