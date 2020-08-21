#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int sumOddNum = 0;
        int sumEvenNum = 1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum % 2 == 1)
            {
                res = (res + sumEvenNum) % 1000000007;
                sumOddNum += 1;
            }
            else
            {
                res = (res + sumOddNum) % 1000000007;
                sumEvenNum += 1;
            }
        }
        return res;
    }
};