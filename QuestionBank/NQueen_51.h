#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

//2020 2-17 15:30

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		//�ӵ����п�ʼ��һ��һ�еؽ����Ϊÿһ����ѡһ�����ʵ���
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
		//Ϊ��curColumn����ѡһ�����ʵ���
		bool hasSolution = false;
		for (int i = 0; i < n; i++)
		{
			if (rowsOK[i])
			{
				bool ok = true;
				//����б���ϵ��Ƿ�ok
				int leftUpRightDown = i - curColumn;  //�м�ȥ����Ⱦ�����ͬһб����
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
					//��i���ʺ�curColumn
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