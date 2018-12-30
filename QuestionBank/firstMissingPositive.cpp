#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int find()
{
	vector<int> nums = { 7,8,9,11,12 };
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	bool haveOne = 0;
	int assumeNum = 2;
	if (nums.size() == 0)
		return 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
		{
			haveOne = 1;
		}
		if (nums[i] > 1 && haveOne)
		{
			if (nums[i] > assumeNum)
				return	assumeNum;
			assumeNum++;
		}
		else if (nums[i] > 1 && !haveOne)
		{
			return	1;
		}
	}
	if (haveOne)
		return assumeNum;
	return 1;
}
int main()
{
	cout << find();
	system("pause");
	return 0;
}