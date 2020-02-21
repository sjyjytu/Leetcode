#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//2020 2-21
//Runtime: 8 ms, faster than 99.15% of C++ online submissions for Minimum Falling Path Sum.
//Memory Usage: 9.8 MB, less than 100.00 % of C++ online submissions for Minimum Falling Path Sum.
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int n = A.size();
		vector<int> oldBest(n, 0);
		vector<int> newBest(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int best = 20200221;
				for (int k = -1; k < 2; k++)
				{
					int index = j + k;
					if (index >=0 && index < n && best > oldBest[index]+A[i][index])
					{
						best = oldBest[index] + A[i][index];
					}
				}
				newBest[j] = best;
			}
			oldBest = newBest;
		}
		int theVeryBest = 20200221;
		for (int i = 0; i < n; i++)
		{
			if (theVeryBest > newBest[i])
			{
				theVeryBest = newBest[i];
			}
		}
		return theVeryBest;
	}
};