#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
		{
			return vector<int>();
		}
		int n = matrix[0].size();
		vector<int> res;
		for (int i = 0; i < m; i++)
		{
			int cur_min_index = 0;
			for (int j = 1; j < n; j++)
			{
				if (matrix[i][j] < matrix[i][cur_min_index])
				{
					cur_min_index = j;
				}
			}
			int cur_min = matrix[i][cur_min_index];
			bool isLuckyNum = true;
			for (int k = 0; k < m; k++)
			{
				if (matrix[k][cur_min_index] > cur_min)
				{
					isLuckyNum = false;
					break;
				}
			}
			if (isLuckyNum)
			{
				res.push_back(cur_min);
			}
		}
		return res;
	}
};