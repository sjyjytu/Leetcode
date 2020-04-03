#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	//�ȼ�¼��һ�У���һ���費��Ҫ���㣬�������С������зֱ�鵽��һ�С���һ��
	void setZeroes(vector<vector<int>>& matrix) {
		bool col0need = false, row0need = false;
		//��һ��
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][0]==0)
			{
				col0need = 1;
				break;
			}
		}
		//��һ��
		for (int i = 0; i < matrix[0].size(); i++)
		{
			if (matrix[0][i] == 0)
			{
				row0need = 1;
				break;
			}
		}
		//�鵽��һ�к͵�һ��
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
		//ɨ��һ�к͵�һ��
		//��һ��
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
		//��һ��
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