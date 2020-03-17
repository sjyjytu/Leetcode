#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	int lay;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x,int layer=1) : val(x), lay(layer),left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> numsSameConsecDiff(int N, int K) {
		vector<int> answer;
		if (N == 1)
			return { 0,1,2,3,4,5,6,7,8,9 };
		TreeNode **root;
		root = new TreeNode*[9];
		for (int i = 1; i < 10; i++)
		{
			root[i - 1] = new TreeNode(i);
			if (pushOneOk(N, K, root[i - 1]))
			{
				getNum(N, root[i - 1], i, answer);
			}
		}
		for (int i = 0; i < 9; i++)
			release(root[i]);
		delete root;
		return answer;
	}
	bool pushOneOk(int N, int K, TreeNode* node)
	{
		if (node->lay < N)
		{
			if (node->val + K < 10)
			{
				node->left = new TreeNode(node->val + K, node->lay + 1);
				pushOneOk(N, K, node->left);
			}
			if (K!=0 &&node->val - K >= 0)
			{
				node->right = new TreeNode(node->val - K, node->lay + 1);
				pushOneOk(N, K, node->right);
			}
			if (node->val + K >= 10 && node->val - K < 0)
				return false;
		}
		return true;
	}

	void getNum(int N, TreeNode *node, int i,vector<int>&answer)
	{
		if (node->lay == N)
		{
			answer.push_back(i);
			return;
		}
		if (node->left)
		{
			getNum(N, node->left, i * 10 + node->left->val, answer);
		}
		if (node->right)
		{
			getNum(N, node->right, i * 10 + node->right->val, answer);
		}
	}
	void release(TreeNode *node)
	{
		if (node->left)
			release(node->left);
		if (node->right)
			release(node->right);
		delete node;
	}
};

int main()
{
	Solution s;
	vector<int> answer = s.numsSameConsecDiff(2, 0);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i]<<"  ";
	}
	system("pause");
	return 0;
}