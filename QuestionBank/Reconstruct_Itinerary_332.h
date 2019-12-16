#include <vector>
#include <string>
#include <unordered_map>
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
		result.insert(result.begin(), src);
		return result;
	}

	//�����ܶ�ѡ���ʱ����ã�����ǰ�ӣ�����һ���ߵ���ͷ��·����һ����ͷ·
	vector<string> gogogo(string src, string back, 
		unordered_map<string, priority_queue<string, vector<string>, cmp>>& path)
	{
		//srcһ��������back��src�Ŀ���û���¼ң������¼��Ǵ�������֧·�������¼Ҿ���back
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
};
