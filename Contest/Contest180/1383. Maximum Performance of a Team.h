#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		vector<pair<int, int>> speed_and_efficiency;
		for (int i = 0; i < n; i++)
		{
			speed_and_efficiency.push_back(make_pair(speed[i], efficiency[i]));
		}
		sort(speed_and_efficiency.begin(), speed_and_efficiency.end(), compare);
		priority_queue<int, vector<int>, greater<int>> min_speed_heap;
		long total_speed = 0;
		long min_efficiency = 0;
		long result = 0;
		for (int i = 0; i < k; i++)
		{
			total_speed += speed_and_efficiency[i].first;
			min_efficiency = speed_and_efficiency[i].second;
			result = max(result, total_speed * min_efficiency);
			min_speed_heap.push(speed_and_efficiency[i].first);
		}
		for (int i = k; i < n; i++)
		{
			if (speed_and_efficiency[i].first > min_speed_heap.top())
			{
				total_speed += speed_and_efficiency[i].first - min_speed_heap.top();
				min_efficiency = speed_and_efficiency[i].second;
				result = max(result, total_speed * min_efficiency);
				min_speed_heap.pop();
				min_speed_heap.push(speed_and_efficiency[i].first);
			}
		}
		return result % 1000000007;
	}
	static bool compare(pair<int, int> a, pair<int, int>b)
	{
		return a.second > b.second;
	}
};