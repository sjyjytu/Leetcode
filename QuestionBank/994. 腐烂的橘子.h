#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		queue<int> q;
		int goodOrangeNum = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					goodOrangeNum++;
				}
				else if (grid[i][j] == 2)
				{
					q.push(i * n + j);
				}
			}
		}
		int needMinute = 0;
		int cnt;
		while (goodOrangeNum > 0)
		{
			cnt = q.size();
			if (cnt == 0)
			{
				return -1;
			}
			needMinute++;
			while (cnt > 0)
			{
				cnt--;
				int top = q.front();
				q.pop();
				int i = top / n;
				int j = top % n;
				if (i > 0 && grid[i - 1][j] == 1)
				{
					grid[i - 1][j] = 2;
					goodOrangeNum--;
					q.push((i - 1) * n + j);
				}
				if (i < m - 1 && grid[i + 1][j] == 1)
				{
					grid[i + 1][j] = 2;
					goodOrangeNum--;
					q.push((i + 1) * n + j);
				}
				if (j > 0 && grid[i][j - 1] == 1)
				{
					grid[i][j - 1] = 2;
					goodOrangeNum--;
					q.push(i * n + j - 1);
				}
				if (j < n - 1 && grid[i][j + 1] == 1)
				{
					grid[i][j + 1] = 2;
					goodOrangeNum--;
					q.push(i * n + j + 1);
				}
			}
		}
		return needMinute;
	}
};