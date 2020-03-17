#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	TreeNode* balanceBST(TreeNode* root) {
		int height;
		return balance(root, height);
	}

	TreeNode* balance(TreeNode* root, int& height)
	{
		if (root==NULL)
		{
			height = 0;
			return NULL;
		}
		else
		{
			int left_height;
			int right_height;
			root->left = balance(root->left, left_height);
			root->right = balance(root->right, right_height);
			while (right_height - left_height > 1)
			{
				//left rotate
				TreeNode* tmp = root->right;
				root->right = root->right->left;
				tmp->left = root;
				root = tmp;
				root->left = balance(root->left, left_height);
				root->right = balance(root->right, right_height);
			}
			while (left_height - right_height > 1)
			{
				//right rotate
				TreeNode* tmp = root->left;
				root->left = root->left->right;
				tmp->right = root;
				root = tmp;
				root->left = balance(root->left, left_height);
				root->right = balance(root->right, right_height);
			}
			height = max(left_height, right_height) + 1;
			return root;
		}
	}
};