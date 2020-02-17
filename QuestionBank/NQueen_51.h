#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

//2020 2-17 15:30

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		//从第零列开始，一列一列地解决，为每一列挑选一个合适的行
		vector<int> chosen(n, -1);
		vector<bool> rowsOK(n, true);
		solve(0, n, chosen, rowsOK);
		return result;
	}

	vector<vector<string>>result;

	bool solve(int curColumn, int n, vector<int> chosen, vector<bool> rowsOK)
	{
		if (curColumn == n)
		{
			vector<string> solution(n, string(n, '.'));
			for (int i = 0; i < n; i++)
			{
				solution[i][chosen[i]] = 'Q';
			}
			result.push_back(solution);
			return true;
		}
		//为第curColumn列挑选一个合适的行
		bool hasSolution = false;
		for (int i = 0; i < n; i++)
		{
			if (rowsOK[i])
			{
				bool ok = true;
				//检验斜线上的是否ok
				int leftUpRightDown = i - curColumn;  //行减去列相等就是在同一斜线上
				int leftDownRightUp = i + curColumn;
				for (int j = 0; j < curColumn; j++)
				{
					if (chosen[j] - j == leftUpRightDown || chosen[j] + j == leftDownRightUp)
					{
						ok = false;
						break;
					}
				}
				if (ok)
				{
					//第i行适合curColumn
					rowsOK[i] = false;
					chosen[curColumn] = i;
					if (solve(curColumn+1, n, chosen, rowsOK))
					{
						hasSolution = true;
					}
					rowsOK[i] = true;
					chosen[curColumn] = -1;
				}
			}
		}
		return hasSolution;
	}
};