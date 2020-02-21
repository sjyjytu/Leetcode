#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
//12.14 9:43 ������Ҳ����ϰ�����˰���ֻ��40ms�Ż���24ms��66%��
class Solution {
private:
	bool has_cycle = 0;
public:
	class Node {
	public:
		//����״̬��0��û�������1���������2�����������ڽӵ�Ҳ�����ʹ��ˣ�2��������Ϊ���ж��ǲ������Ƚڵ�
		int visited;
		vector<int> neighbors;

		Node() { visited = 0; }

		Node(vector<int> _neighbors) {
			visited = 0;
			neighbors = _neighbors;
		}
	};
	//�Ƚ�һ��ͼ�������������������û�лرߣ��п����ж������ͨ��ͼ
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

		//����
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
					//����Ƿ��ǻرߣ���src�ǲ���neighbors[i]������
					return false;
				}
			}
		}
		val2Node[src]->visited = 2;
		return true;
	}
};