#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
	int curMax = 0;
public:
	int diameterOfBinaryTree(TreeNode* root) {
		height(root);
		return curMax;
	}

	int height(TreeNode* node)
	{
		if (node==NULL)
		{
			return 0;
		}
		else
		{
			int lh = height(node->left);
			int rh = height(node->right);
			if (lh + rh > curMax)
			{
				curMax = lh + rh;
			}
			return max(lh, rh) + 1;
		}
	}
};