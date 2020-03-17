//#include <iostream>
//using namespace std;
//
////Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	bool isUnivalTree(TreeNode* root) {
//		int value = root->val;
//		if (searchTree(root, value))
//			return true;
//		return false;
//	}
//	bool searchTree(TreeNode* node, int value)
//	{
//		if (value != node->val)
//			return false;
//		if (node->left)
//		{
//			if (!searchTree(node->left,value))
//			{
//				return false;
//			}
//		}
//		if (node->right)
//		{
//			if (!searchTree(node->right,value))
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};

//int main()
//{
//	TreeNode *root = new TreeNode(1);
//	root->left = new TreeNode(1);
//	root->right = new TreeNode(1);
//	root->left->left = new TreeNode(2);
//	Solution s;
//	cout << s.isUnivalTree(root);
//	system("pause");
//	return 0;
//}