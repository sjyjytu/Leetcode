#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
//12.17
//深搜，如果遇到访问过的，那这条就是回边，但是难判断哪个是最后一条出现在最后，可以记录全部路径
//广搜，如果遇到节点在队列中（准备被访问），就发现环了，还是不知道谁是最后
class Solution {
public:
	//深搜并后序加入节点，打败34%，主要是返回最后一边太慢了
	//果然，直接从后往前找最后一边，就0ms，100%了，不过有点费内存
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();  //有n个节点就有n条边
		vector<vector<int>> neibors(n + 1);  //直接研究1-n好了，就不转为0~n-1了
		vector<int> visited(n + 1);
		for (int i = 0; i < n; i++)
		{
			neibors[edges[i][0]].push_back(edges[i][1]);
			neibors[edges[i][1]].push_back(edges[i][0]);
		}
		unordered_map<int, unordered_set<int>>cycle;
		int end = 0;
		dfs(1, 0, end, neibors, visited, cycle);

		//判断cycle中哪条边是edges中最后出现的
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
				//找到回边
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
