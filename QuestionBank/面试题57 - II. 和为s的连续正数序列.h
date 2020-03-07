#include <vector>
using namespace std;

class Solution {
public:
	//经典的先往右扩张，再从左收缩
	vector<vector<int>> findContinuousSequence(int target) {
		int beginNum = 1;
		int curNum = 1;
		int total = 1;
		vector<vector<int>>result;
		while (beginNum <= target / 2 )
		{
			while (total<target)
			{
				curNum++;
				total += curNum;
			}
			if (total==target)
			{
				vector<int>oneres;
				for (int i = beginNum; i <= curNum; i++)
				{
					oneres.push_back(i);
				}
				result.push_back(oneres);
				curNum++;
				total += curNum;
			}
			while (total>target)
			{
				total -= beginNum;
				beginNum++;
			}
			if (total == target)
			{
				vector<int>oneres;
				for (int i = beginNum; i <= curNum; i++)
				{
					oneres.push_back(i);
				}
				result.push_back(oneres);
				total -= beginNum;
				beginNum++;
			}
		}
		return result;
	}
};