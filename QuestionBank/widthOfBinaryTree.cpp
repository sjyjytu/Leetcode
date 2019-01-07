/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		queue<pair<TreeNode*, int> > bfsQue;
		bfsQue.push({ root,1 });
		int lLeft = 1;
		int lastNum = 0;
		int maxWidth = 0;
		int curLayer = 1;
		pair<TreeNode*, int> curPair = bfsQue.front();
		bfsQue.pop();
		while (curPair.first)
		{
			TreeNode* curNode = curPair.first;
			int curNum = curPair.second;
			if (curNum > (1 << curLayer) - 1)
			{
				//Ô½²ãÁË
				maxWidth = max(maxWidth, lastNum - lLeft + 1);
				lLeft = curNum;
				curLayer++;
			}
			lastNum = curNum;
			if (curNode->left)
				bfsQue.push({ curNode->left,curPair.second * 2 });
			if (curNode->right)
				bfsQue.push({ curNode->right,curPair.second * 2 + 1 });

			if (!bfsQue.empty())
			{
				curPair = bfsQue.front();
				bfsQue.pop();
			}
			else
				curPair.first = NULL;

		}
		maxWidth = max(maxWidth, lastNum - lLeft + 1);
		return maxWidth;
	}
};