#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

//p1
class Solution {
public:
	int findLucky(vector<int>& arr) {
		map<int, int> num2fre;
		for (int i = 0; i < arr.size(); i++)
		{
			num2fre[arr[i]]++;
		}
		for (auto it = num2fre.rbegin(); it != num2fre.rend(); it++)
		{
			if (it->first==it->second)
			{
				return it->first;
			}
		}
		return -1;
	}
};

//p2
class Solution2 {
public:
	int numTeams(vector<int>& rating) {
		int result = 0;
		for (int i = 0; i < rating.size(); i++)
		{
			for (int j = i+1; j < rating.size(); j++)
			{
				if (rating[i] < rating[j])
				{
					for (int k = j + 1; k < rating.size(); k++)
					{
						if (rating[j]<rating[k])
						{
							result++;
						}
					}
				}
				else
				{
					for (int k = j + 1; k < rating.size(); k++)
					{
						if (rating[j] > rating[k])
						{
							result++;
						}
					}
				}
			}
		}
		return result;
	}
};


//p3
class UndergroundSystem {
private:
	unordered_map<int, pair<string, int>> id2ci;
	unordered_map<string, pair<long, int>> path2totaltime;
public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		id2ci[id] = make_pair(stationName, t);
	}

	void checkOut(int id, string stationName, int t) {
		pair<string, int> ci_info = id2ci[id];
		string path = ci_info.first + ":" + stationName;
		int time = t - ci_info.second;
		path2totaltime[path].first += time;
		path2totaltime[path].second += 1;
	}

	double getAverageTime(string startStation, string endStation) {
		string path = startStation + ":" + endStation;
		return double(path2totaltime[path].first) / path2totaltime[path].second;
	}
};

//p4
class Solution4 {
public:
	int findGoodStrings(int n, string s1, string s2, string evil) {
		int base = 26;
		int cur_base = 1;
		int total = 0;
		for (int i = n-1; i >= 0; i--)
		{
			total += (s2[i] - s1[i]) * cur_base;
			cur_base *= base;
		}
		if (total >= 0)
		{
			total += 1;
		}
		else
		{
			total = 0;
		}
		return total;
	}
};