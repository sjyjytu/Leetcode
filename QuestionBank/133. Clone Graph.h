#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
//12.13 8:30-9:50 ʱ��73% �ռ�6% �����֪������ɱŮ���Ƕ�����ѧ�㣬�е㲻֪����
//10:06 ��unordered_map�Ż���һ�£�ʱ�䲻�䣬�ռ�96%�ˣ�����Ҫ�ú�stl�⣬�Ͼ��Լ�������û����Ҳ����
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		//vector<Node*>been_to_visit;
		//vector<Node*>been_to_copy;
		queue<Node*> to_visit;
		queue<Node*> to_copy;
		Node* copy = new Node();
		to_visit.push(node);
		to_copy.push(copy);
		//been_to_visit.push_back(node);
		//been_to_copy.push_back(copy);
		unordered_map<Node*, Node*> visit_to_copy;
		visit_to_copy[node] = copy;
		Node* cur_visit;
		Node* cur_copy;
		while (!to_visit.empty())
		{
			cur_visit = to_visit.front();
			cur_copy = to_copy.front();
			to_visit.pop();
			to_copy.pop();
			cur_copy->val = cur_visit->val;
			for (int i = 0; i < cur_visit->neighbors.size(); i++)
			{
				//int index = has_it(been_to_visit, cur_visit->neighbors[i]);
				unordered_map<Node*, Node*>::iterator it = visit_to_copy.find(cur_visit->neighbors[i]);
				if (it == visit_to_copy.end())
				{
					Node* new_copy = new Node();
					cur_copy->neighbors.push_back(new_copy);
					to_copy.push(new_copy);
					to_visit.push(cur_visit->neighbors[i]);
					//been_to_visit.push_back(cur_visit->neighbors[i]);
					//been_to_copy.push_back(new_copy);
					visit_to_copy[cur_visit->neighbors[i]] = new_copy;
				}
				else
				{
					//cur_copy->neighbors.push_back(been_to_copy[index]);
					cur_copy->neighbors.push_back(it->second);
				}
			}
			
		}
		return copy;
	}

	int has_it(vector<Node*> nodes, Node* node)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i]==node)
			{
				return i;
			}
		}
		return -1;
	}
};

