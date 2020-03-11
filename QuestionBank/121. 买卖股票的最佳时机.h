#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
		{
			return 0;
		}
		int curMin = prices[0];
		int maxProfit = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] - curMin > maxProfit)
			{
				maxProfit = prices[i] - curMin;
			}
			if (prices[i] < curMin)
			{
				curMin = prices[i];
			}
		}
		return maxProfit;
	}
};