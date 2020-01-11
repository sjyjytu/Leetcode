#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> vec(n, vector<int>(n, 0));
		int middle = n / 2;
		if ((n & 1) == 1)
		{
			middle++;
		}
		for (int i = 0; i < middle; i++)
		{
			int beginPos = i, endPos = n - i;
			for (int j = 0; j < beginPos; j++)
			{
				int artpoint = (j+1) * 4 * (n - (j+1));  //4i*(n-i)
				vec[i][j] = artpoint + (j+1)-i;
			}
			for (int j = beginPos; j < endPos; j++)
			{
				int artpoint = i * 4 * (n - i) + j - i + 1;
				vec[i][j] = artpoint;
			}
			for (int j = endPos; j < n; j++)
			{
				int artI = n - j - 1;
				int artpoint = (n - artI) * 4 * artI + n-2*artI;  //i = n-j-1
				vec[i][j] = artpoint + i - artI;
			}
		}

		for (int i = middle; i < n; i++)
		{
			int beginPos = n-1-i, endPos = i;
			int arti = n - i;  // arti = n - i, leftdown = 4arti*(n-arti)-n-j-1
			int leftdown = 4 * arti * (n - arti) - (n - 2 * (beginPos + 1));
			for (int j = 0; j < beginPos; j++)
			{
				int artpoint = (j + 1) * 4 * (n - (j + 1));  //4i*(n-i)
				vec[i][j] = artpoint + (j + 1) - i;
			}
			for (int j = beginPos; j < endPos; j++)
			{
				vec[i][j] = leftdown -(j-beginPos);
				//vec[i][j] = -1;
			}
			for (int j = endPos; j < n; j++)
			{
				int artI = n - j - 1;
				int artpoint = (n - artI) * 4 * artI + n - 2 * artI;  //i = n-j-1
				vec[i][j] = artpoint + i - artI;
			}
		}
		return vec;
	}
};