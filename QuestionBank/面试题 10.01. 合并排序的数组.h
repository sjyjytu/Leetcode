#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		vector<int> tmp(m + n);
		int aindex = 0, bindex = 0, tindex = 0;
		while (aindex < m && bindex < n)
		{
			if (A[aindex] < B[bindex])
			{
				tmp[tindex++] = A[aindex++];
			}
			else
			{
				tmp[tindex++] = B[bindex++];
			}
		}
		while (aindex < m)
		{
			tmp[tindex++] = A[aindex++];
		}
		while (bindex < n)
		{
			tmp[tindex++] = B[bindex++];
		}
		for (int i = 0; i < m + n; i++)
		{
			A[i] = tmp[i];
		}
	}
};