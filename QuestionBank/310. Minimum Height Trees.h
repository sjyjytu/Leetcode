#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	//暴力搜索所有节点作为根节点时的高度，不负众望地超时了。
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		int minHeight = n;
		vector<vector<int>>val2Neighbors(n);
		vector<int> val2Height(n);
		for (int i = 0; i < edges.size(); i++)
		{
			int a = edges[i][0], b = edges[i][1];
			val2Neighbors[a].push_back(b);
			val2Neighbors[b].push_back(a);
		}

		for (int i = 0; i < n; i++)
		{
			//i 作为根节点
			vector<bool> visited(n);
			val2Height[i] = dfs(i, 0, minHeight, visited, val2Neighbors);
			if (val2Height[i] < minHeight)
			{
				minHeight = val2Height[i];
			}
		}

		vector<int> result;
		for (int i = 0; i < n; i++)
		{
			if (minHeight==val2Height[i])
			{
				result.push_back(i);
			}
		}
		return result;
	}

	//若高度小于最小高度，更新最小高度,返回最小高度，否则，返回最小高度+1
	int dfs(int node, int curHeight, int& minHeight, vector<bool>& visited, vector<vector<int>>& val2Neighbors)
	{
		visited[node] = 1;
		int maxHeight = curHeight;
		for (int i = 0; i < val2Neighbors[node].size(); i++)
		{
			if (visited[val2Neighbors[node][i]] == 0)
			{
				int nextHeight = dfs(val2Neighbors[node][i], curHeight + 1, minHeight, visited, val2Neighbors);
				if (nextHeight > maxHeight)
				{
					maxHeight = nextHeight;
				}
			}
		}
		return maxHeight;
	}

	//看了别人的，，自己看错题了，原来本来给的就是一颗树，无回路
	//84ms 52%
	vector<int> findMinHeightTrees2(int n, vector<vector<int>>& edges) {
		if (n==1)
		{
			return { 0 };
		}
		//不断去掉叶子节点，剩下的1或2个点就是最小高度树的根节点
		vector<unordered_set<int>>adjs(n);
		for (int i = 0; i < edges.size(); i++)
		{
			int a = edges[i][0], b = edges[i][1];
			adjs[a].insert(b);
			adjs[b].insert(a);
		}

		queue<int> leaves;
		for (int i = 0; i < n; i++)
		{
			if (adjs[i].size() == 1)
			{
				leaves.push(i);
			}
		}

		while (n > 2)
		{
			int size = leaves.size();
			n -= size;
			while (size-->0)
			{
				int to_clear = leaves.front();
				leaves.pop();
				int its_only_brother = *adjs[to_clear].begin();
				adjs[its_only_brother].erase(to_clear);
				if (adjs[its_only_brother].size()==1)
				{
					leaves.push(its_only_brother);
				}
			}
		}

		vector<int> result;
		while (!leaves.empty())
		{
			result.push_back(leaves.front());
			leaves.pop();
		}
		return result;
	}
};