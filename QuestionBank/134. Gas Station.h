#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int begin_index = 0;  //开始的点
		int cur_count;  //走过的点数
		int sum;
		while (begin_index < n)
		{
			cur_count = 0;
			sum = 0;
			while (sum >= 0 && cur_count < n)
			{
				int index = (begin_index + cur_count) % n;
				sum += gas[index] - cost[index];
				cur_count++;
			}
			if (sum < 0)
			{
				begin_index = begin_index + cur_count;
			}
			else if (cur_count == n)
			{
				return begin_index;
			}
		}
		return -1;
	}
};