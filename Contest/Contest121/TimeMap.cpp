#pragma once
#include <string>
#include <map>
#include <iterator>
using namespace std;
class TimeMap
{
public:
	TimeMap()
	{

	}
	~TimeMap()
	{

	}
	void set(string key, string value, int timestamp)
	{
		timeMap[key][timestamp] = value;
	}
	string get(string key, int timestamp)
	{
		//not found key
		if (timeMap.find(key) == timeMap.end())
		{
			return "";
		}
		//the min set time > timestamp
		else if (timeMap[key].begin()->first>timestamp)
		{
			return "";
		}
		else
		{
			//set times contain timestamp
			if (timeMap[key].find(timestamp) != timeMap[key].end())
				return timeMap[key][timestamp];
			//timestamp > the max set time
			if (timestamp >= prev(timeMap[key].end())->first)
				return prev(timeMap[key].end())->second;
			//search the max one < timestamp from behind
			auto it = prev(timeMap[key].end());
			for (; it!= timeMap[key].begin();it--)
			{
				if (it->first < timestamp)
				{
					return it->second;
				}
			}
			return timeMap[key].begin()->second;
		}
	}
private:
	map<string, map<int, string> >timeMap;
};

