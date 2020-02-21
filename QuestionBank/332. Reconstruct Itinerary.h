#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
//12.16 д���ĸ�Сʱ���ң�ֻ����5%��������̫�����ˡ�
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
		return result;
	}

	//�����ܶ�ѡ���ʱ����ã�����ǰ�ӣ�����һ���ߵ���ͷ��·����һ����ͷ·
	vector<string> gogogo(string src, string back, 
		unordered_map<string, priority_queue<string, vector<string>, cmp>>& path)
	{
		vector<string> result = { src };
		//srcһ��������back��src�Ŀ���û���¼ң������¼��Ǵ�������֧·�������¼Ҿ���back
		if (path.count(src)==0 || path[src].size()==0)
		{
			return result;
		}

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
			int size = one_special_roal.size();
			if (one_special_roal[size -1] == src)
			{
				//����һ����src�������ص�src��·��ֱ�Ӽӵ�result����
				result.insert(result.end(), one_special_roal.begin(), one_special_roal.end());
			}
			else
			{
				//����һ���ߵ���ͷ��·��ֻ���ܳ���һ�λ���Σ�Ӧ�÷ŵ�result��β��
				should_add_to_back = one_special_roal;
			}
		}
		if (should_add_to_back.size()>0)
		{
			result.insert(result.end(), should_add_to_back.begin(), should_add_to_back.end());
		}
		return result;
	}

	//�������ɵ�ˣ���tm��dfs��reverse
	vector<string> findItinerary2(vector<vector<string>>& tickets) {
		unordered_map<string, priority_queue<string, vector<string>, greater<string>>> path;
		for (int i = 0; i < tickets.size(); i++)
		{
			path[tickets[i][0]].push(tickets[i][1]);
		}
		string src = "JFK";
		vector<string> result;
		dfs(src, result, path);
		reverse(result.begin(), result.end());
		return result;
	}

	void dfs(string node, vector<string>& result,
		unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& path)
	{
		if (path.count(node) == 0 || path[node].size() == 0)
		{
			result.push_back(node);
			return;
		}
		string next;
		while (!path[node].empty())
		{
			next = path[node].top();
			path[node].pop();
			dfs(next, result, path);
		}
		path.erase(node);
		result.push_back(node);
	}
};
