#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	TreeNode* balanceBST(TreeNode* root) {
		vector<int> res;
		MidVisit(root, res);
		cout << res.size();
		return BuildTree(res, 0, res.size() - 1);
	}

	void MidVisit(TreeNode* node, vector<int>& res)
	{
		if (node == NULL)
		{
			return;
		}
		MidVisit(node->left, res);
		res.push_back(node->val);
		MidVisit(node->right, res);
	}

	TreeNode* BuildTree(vector<int>& res, int left, int right)
	{
		if (right < left)
		{
			return NULL;
		}
		else
		{
			int mid = (left + right) / 2;
			TreeNode* node = new TreeNode(res[mid]);
			node->left = BuildTree(res, left, mid - 1);
			node->right = BuildTree(res, mid + 1, right);
			return node;
		}
	}
};