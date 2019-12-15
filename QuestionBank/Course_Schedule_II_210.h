#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
//12.15
class Solution {
public:

	//�Ƚ�һ��ͼ�������������������û�лرߣ��п����ж������ͨ��ͼ
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> visited(numCourses);
		vector<vector<int>>val2Neighbors(numCourses);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int src = prerequisites[i][0], dst = prerequisites[i][1];
			val2Neighbors[src].push_back(dst);
		}

		//����
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
				//����Ƿ��ǻرߣ���src�ǲ���neighbors[i]������
				return false;
			}
		}
		visited[src] = 2;
		results.push_back(src);
		return true;
	}
};