#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			sum += A[i];
		}
		if (sum % 3 != 0)
		{
			return false;
		}
		int target = sum / 3;
		bool flag1 = false;
		int curSum = 0;
		int index = 0;
		for (int i = 0; i < A.size(); i++)
		{
			curSum += A[i];
			if (curSum == target)
			{
				curSum = 0;
				if (!flag1)
				{
					flag1 = true;
				}
				else
				{
					return A.size() - i > 1;
				}
			}
		}
		return false;
	}
};