#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> minCost(31, 0);
		int iterDay = 1;
		for (int i = 0; i < days.size(); i++)
		{
			int date = days[i];
			while (iterDay < date)
			{
				minCost[iterDay % 31] = minCost[(iterDay - 1) % 31];
				iterDay++;
			}
			iterDay++;
			int curMin = minCost[(date - 1 + 31) % 31] + costs[0];
			curMin = min(curMin, minCost[(date - 7 + 31) % 31] + costs[1]);
			curMin = min(curMin, minCost[(date - 30 + 31) % 31] + costs[2]);
			minCost[date % 31] = curMin;
		}
		return minCost[days[days.size()-1] % 31];
	}
};