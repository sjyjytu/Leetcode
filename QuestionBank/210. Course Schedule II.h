#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
//12.15
class Solution {
public:

	//先建一个图，再深度优先搜索看有没有回边，有可能有多个不连通的图
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> visited(numCourses);
		vector<vector<int>>val2Neighbors(numCourses);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int src = prerequisites[i][0], dst = prerequisites[i][1];
			val2Neighbors[src].push_back(dst);
		}

		//深搜
		vector<int> results;
		for (int i = 0; i<numCourses;i++)
		{
			if (visited[i] == 0)
			{
				if (!dfs(i, visited, val2Neighbors, results)) return {};
			}
		}
		return results;
	}

	bool dfs(int src, vector<int> &visited, vector<vector<int>>& val2Neighbors, vector<int>&results)
	{
		visited[src] = 1;
		vector<int> neighbors = val2Neighbors[src];
		for (int i = 0; i < neighbors.size(); i++)
		{
			if (visited[neighbors[i]] == 0)
			{
				if (!dfs(neighbors[i], visited, val2Neighbors, results))
				{
					return false;
				}
			}
			else if (visited[neighbors[i]] == 1)
			{
				//检查是否是回边，即src是不是neighbors[i]的祖先
				return false;
			}
		}
		visited[src] = 2;
		results.push_back(src);
		return true;
	}
};