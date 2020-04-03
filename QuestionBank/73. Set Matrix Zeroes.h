#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	//先记录第一行，第一列需不需要归零，把其他行、其他列分别归到第一行、第一列
	void setZeroes(vector<vector<int>>& matrix) {
		bool col0need = false, row0need = false;
		//第一列
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][0]==0)
			{
				col0need = 1;
				break;
			}
		}
		//第一行
		for (int i = 0; i < matrix[0].size(); i++)
		{
			if (matrix[0][i] == 0)
			{
				row0need = 1;
				break;
			}
		}
		//归到第一行和第一列
		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 1; j < matrix[i].size(); j++)
			{
				if (matrix[i][j]==0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		//扫第一行和第一列
		//第一列
		for (int i = 1; i < matrix.size(); i++)
		{
			if (matrix[i][0] == 0)
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		//第一行
		for (int i = 1; i < matrix[0].size(); i++)
		{
			if (matrix[0][i] == 0)
			{
				for (int j = 0; j < matrix.size(); j++)
				{
					matrix[j][i] = 0;
				}
			}
		}

		if (row0need)
		{
			for (int i = 0; i < matrix[0].size(); i++)
			{
				matrix[0][i] = 0;
			}
		}

		if (col0need)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				matrix[i][0] = 0;
			}
		}
	}
};