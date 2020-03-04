#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
//12ms 96% 26.7M 24%

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = postorder.size();
		if (n <= 0)
		{
			return NULL;
		}
		unordered_map<int, int>inValue2Index;
		for (int i = 0; i < n; i++)
		{
			inValue2Index[inorder[i]] = i;
		}
		
		return buildSubTree(n - 1, 0, n - 1, inValue2Index, postorder);
	}

	TreeNode* buildSubTree(int postRootIndex, int inLeftIndex, int inRightIndex, 
		unordered_map<int, int>&inValue2Index, vector<int>& postorder)
	{
		if (inLeftIndex > inRightIndex)
		{
			return NULL;
		}
		int root = postorder[postRootIndex];
		TreeNode* subRoot = new TreeNode(root);
		if (inLeftIndex == inRightIndex)
		{
			return subRoot;
		}
		
		int inRootIndex = inValue2Index[root];
		int rightTreeNodeNum = inRightIndex - inRootIndex;
		subRoot->right = buildSubTree(postRootIndex - 1, inRootIndex + 1, inRightIndex, inValue2Index, postorder);
		subRoot->left = buildSubTree(postRootIndex - rightTreeNodeNum - 1, inLeftIndex, inRootIndex - 1, inValue2Index, postorder);
		return subRoot;
	}
};