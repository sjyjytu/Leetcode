#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
//12.16 写了四个小时左右，只超过5%。。。我太垃圾了。
class Solution {
public:
	struct cmp
	{
		bool operator ()(string s1, string s2)
		{
			return strcmp(s1.c_str(), s2.c_str()) >= 0;
		}
	};
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		unordered_map<string, priority_queue<string, vector<string>, cmp>> path;
		for (int i = 0; i < tickets.size(); i++)
		{
			string src = tickets[i][0], dst = tickets[i][1];
			path[src].push(dst);
		}
		string src = "JFK";
		vector<string> result = gogogo(src, "", path);
		result.insert(result.begin(), src);
		return result;
	}

	//遇到很多选择的时候调用，不计前嫌，返回一条走到尽头的路或者一条回头路
	vector<string> gogogo(string src, string back, 
		unordered_map<string, priority_queue<string, vector<string>, cmp>>& path)
	{
		//src一定不等于back，src的可能没有下家，可能下家是带分流的支路，可能下家就是back
		if (path.count(src)==0 || path[src].size()==0)
		{
			return {};
		}
		vector<string> result;
		while (path[src].size()==1)
		{
			string next = path[src].top();
			path[src].pop();
			result.push_back(next);
			src = next;
			if (next == back)
			{
				return result;
			}
		}
		vector<string> should_add_to_back;

		while(!path[src].empty())
		{
			string next = path[src].top();
			path[src].pop();
			vector<string> one_special_roal = gogogo(next, src, path);
			one_special_roal.insert(one_special_roal.begin(), next);
			int size = one_special_roal.size();
			if (one_special_roal[size -1] == src)
			{
				//这是一条从src出发，回到src的路，直接加到result后面
				result.insert(result.end(), one_special_roal.begin(), one_special_roal.end());
			}
			else
			{
				//这是一条走到尽头的路，只可能出现一次或零次，应该放到result的尾部
				should_add_to_back = one_special_roal;
			}
		}
		if (should_add_to_back.size()>0)
		{
			result.insert(result.end(), should_add_to_back.begin(), should_add_to_back.end());
		}
		return result;
	}
};
