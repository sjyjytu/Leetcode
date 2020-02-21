#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
//12.17
//���ѣ�����������ʹ��ģ����������ǻرߣ��������ж��ĸ������һ����������󣬿��Լ�¼ȫ��·��
//���ѣ���������ڵ��ڶ����У�׼�������ʣ����ͷ��ֻ��ˣ����ǲ�֪��˭�����
class Solution {
public:
	//���Ѳ��������ڵ㣬���34%����Ҫ�Ƿ������һ��̫����
	//��Ȼ��ֱ�ӴӺ���ǰ�����һ�ߣ���0ms��100%�ˣ������е���ڴ�
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();  //��n���ڵ����n����
		vector<vector<int>> neibors(n + 1);  //ֱ���о�1-n���ˣ��Ͳ�תΪ0~n-1��
		vector<int> visited(n + 1);
		for (int i = 0; i < n; i++)
		{
			neibors[edges[i][0]].push_back(edges[i][1]);
			neibors[edges[i][1]].push_back(edges[i][0]);
		}
		unordered_map<int, unordered_set<int>>cycle;
		int end = 0;
		dfs(1, 0, end, neibors, visited, cycle);

		//�ж�cycle����������edges�������ֵ�
		for (int i = n-1; i >= 0; i--)
		{
			int a = edges[i][0], b = edges[i][1];
			if (cycle.count(a) != 0 && cycle[a].count(b) != 0)
			{
				return { min(a,b), max(a,b) };
			}
		}
	}

	bool dfs(int node, int last, int &end,
		vector<vector<int>>& neibors, vector<int>& visited, unordered_map<int, unordered_set<int>>&cycle)
	{
		visited[node] = 1;
		for (int i = 0; i < neibors[node].size(); i++)
		{
			int next = neibors[node][i];
			if (last == next)
			{
				continue;
			}
			if (visited[next])
			{
				//�ҵ��ر�
				cycle[node].insert(next);
				cycle[next].insert(node);
				end = next;
				return true;
			}
			if (dfs(next, node, end, neibors, visited, cycle))
			{
				cycle[node].insert(next);
				cycle[next].insert(node);
				return end != node;
			}
		}
		return false;
	}
};
