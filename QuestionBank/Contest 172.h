#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximum69Number(int num) {
		string s = to_string(num);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i]=='6')
			{
				s[i] = '9';
				break;
			}
		}
		return atoi(s.c_str());
	}
};

class Solution2 {
public:
	vector<string> printVertically(string s) {
		vector<string> ss;
		int maxLength = 0;
		while (!s.empty())
		{
			int pos = s.find(" ");
			if (pos == string::npos) //如果没有空格了，则只剩下最后一个整数字符，转换为数字加入数组并清空字符串，使循环结束
			{
				ss.push_back(s);
				maxLength = s.size() > maxLength ? s.size() : maxLength;
				s.clear();
				break;
			}
			string s_temp = s.substr(0, pos);
			maxLength = s_temp.size() > maxLength ? s_temp.size() : maxLength;
			ss.push_back(s_temp);
			s.erase(0, pos + 1); //要删掉空格，所以要s.find(" ") + 1
		}
		vector<string> res(maxLength, "");
		for (int i = 0; i < maxLength; i++)
		{
			for (int j = 0; j < ss.size(); j++)
			{
				if (i < ss[j].size())
				{
					res[i].push_back(ss[j][i]);
				}
				else
				{
					res[i].push_back(' ');
				}
				
			}
		}
		//删空格
		for (int i = 0; i < res.size(); i++)
		{
			while (res[i].size()>0&&res[i].back()==' ')
			{
				res[i].pop_back();
			}
		}
		return res;
	}
};


class Solution3 {
public:
	// Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	//后序遍历
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if (postOrder(root, target))
		{
			return NULL;
		}
		return root;
	}

	bool postOrder(TreeNode* node, int target)
	{
		if (node->left != NULL)
		{
			if (postOrder(node->left, target))
			{
				node->left = NULL;
			}
		}
		if (node->right != NULL)
		{
			if (postOrder(node->right, target))
			{
				node->right = NULL;
			}
		}
		if (node->left == NULL && node->right == NULL)
		{
			if (node->val == target)
			{
				return true;
			}
		}
		return false;
	}
};

class Solution4 {
public:
	//贪心算法，最小集合覆盖
	int minTaps(int n, vector<int>& ranges) {
		vector<bool>covered(n + 1, 0);
		vector<bool>used(n + 1, 0);
		bool ok = false;
		int water_num = 0;
		while (!ok)
		{
			int bestTap = -1;
			int bestCoverNum = -1;
			for (int i = 0; i < n + 1; i++)
			{
				int curCoverNum = 0;
				if (!used[i] && ranges[i]!=0)
				{
					for (int j = max(0, i-ranges[i]); j <= min(n,i+ranges[i]); j++)
					{
						if (!covered[j])
						{
							curCoverNum++;
						}
					}
					if (curCoverNum > bestCoverNum)
					{
						bestTap = i;
						bestCoverNum = curCoverNum;
					}
				}
			}
			if (bestTap!=-1)
			{
				used[bestTap] = 1;
				water_num++;
				cout << bestTap << endl;
				for (int j = max(0, bestTap - ranges[bestTap]); j <= min(n, bestTap + ranges[bestTap]); j++)
				{
					covered[j] = 1;
				}
				ok = true;
				for (int i = 0; i < n + 1; i++)
				{
					if (!covered[i])
					{
						ok = false;
						break;
					}
				}
			}
			else
			{
				return -1;
			}
		}
		return water_num;
		
	}
};