#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int longest = 0;
public:
    int longestZigZag(TreeNode* root) {
        return max(max(longestZigZagBeginFromNode(root, 0), longestZigZagBeginFromNode(root, 1)),longest);
    }

    int longestZigZagBeginFromNode(TreeNode* node, int direction)
    {
        TreeNode* next = direction == 0 ? node->left : node->right;
        if (next==NULL)
        {
            return 0;
        }
        int nodeIsBeginPos = longestZigZagBeginFromNode(next, 1 - direction);
        int nodeIsNotBeginPos = longestZigZagBeginFromNode(next, direction);
        if (nodeIsNotBeginPos > longest)
        {
            longest = nodeIsNotBeginPos;
        }
        return nodeIsBeginPos+1;
    }
};