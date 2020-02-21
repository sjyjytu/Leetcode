#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
//12.14 9:43 考六级也不复习，调了半天只从40ms优化到24ms，66%。
class Solution {
private:
	bool has_cycle = 0;
public:
	class Node {
	public:
		//三个状态，0：没到达过，1：到达过，2：它的所有邻接点也都访问过了；2的引入是为了判断是不是祖先节点
		int visited;
		vector<int> neighbors;

		Node() { visited = 0; }

		Node(vector<int> _neighbors) {
			visited = 0;
			neighbors = _neighbors;
		}
	};
	//先建一个图，再深度优先搜索看有没有回边，有可能有多个不连通的图
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, Node*> val2Node;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int src = prerequisites[i][0], dst = prerequisites[i][1];
			if (val2Node.count(src)==0)
			{
				val2Node[src] = new Node({ dst });
			}
			else
			{
				val2Node[src]->neighbors.push_back(dst);
			}
		}

		//深搜
		for (auto it = val2Node.begin();it!=val2Node.end();it++)
		{
			if (it->second->visited==0)
			{
				if(!dfs(it->first, val2Node)) return false;
			}
		}
		return true;
	}

	bool dfs(int src, unordered_map<int, Node*>& val2Node)
	{
		val2Node[src]->visited = 1;
		vector<int> neighbors = val2Node[src]->neighbors;
		for (int i = 0; i < neighbors.size(); i++)
		{
			if (val2Node.count(neighbors[i]) != 0)
			{
				if (val2Node[neighbors[i]]->visited == 0)
				{
					if (!dfs(neighbors[i], val2Node))
					{
						return false;
					}
				}
				else if (val2Node[neighbors[i]]->visited == 1)
				{
					//检查是否是回边，即src是不是neighbors[i]的祖先
					return false;
				}
			}
		}
		val2Node[src]->visited = 2;
		return true;
	}
};