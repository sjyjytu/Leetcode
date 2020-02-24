#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<algorithm>

using namespace std;

//Runtime: 32 ms, faster than 88.20% of C++ online submissions for Largest Values From Labels.
//Memory Usage : 19.2 MB, less than 100.00 % of C++ online submissions for Largest Values From Labels.
class Solution {
public:
	static bool compare(pair<int, int>a, pair<int, int>b)
	{
		return a.first > b.first;
	}
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<pair<int, int>>valueLabel;
		vector<int> useCount(20000, 0);
		for (int i = 0; i < values.size(); i++)
		{
			valueLabel.push_back(make_pair(values[i], labels[i]));
		}
		sort(valueLabel.begin(), valueLabel.end(), compare);
		int sum = 0;
		int num = 0;
		for (int i = 0; i < valueLabel.size() && num <num_wanted; i++)
		{
			if (useCount[valueLabel[i].second]<use_limit)
			{
				sum += valueLabel[i].first;
				useCount[valueLabel[i].second]++;
				num++;
			}
		}
		return sum;
	}
};