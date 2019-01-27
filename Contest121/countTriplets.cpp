#include <vector>
#include <iostream>
using namespace std;
// 0000 0110 1001 0000 1101 1011
//n个数 m个零 n-m个非零C31*m*(n-m)*(n-m)+C32*m*m*(n-m)+C33*m*m*m
class Solution {
public:
	int countTriplets(vector<int>& A) {
		vector<int> cnt(65536, 0);
		for (int i = 0; i<2048; i++) {
			for (int n : A) {
				if ((i&n) == 0) cnt[i]++;
			}
		}

		int res = 0;
		for (int a : A)
			for (int b : A) {
				res += cnt[a&b];
			}
		return res;
	}
}; 
int main()
{
	Solution s;
	vector<int> A = { 23,364,854,368,318,669,250,246,619,234,296,1017,966,925,856,615,825,871,264,977 };
	cout << s.countTriplets(A);
	system("pause");
	return 0;
}