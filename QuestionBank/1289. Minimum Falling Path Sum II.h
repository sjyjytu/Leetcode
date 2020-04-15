#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
#define MAX_VALUE 20000
        vector<vector<int>>dp(m, vector<int>(n, 0));
        int lastMin = MAX_VALUE, lastMin2 = MAX_VALUE, lastMinIndex;
        int thisMin = MAX_VALUE, thisMin2 = MAX_VALUE, thisMinIndex;
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = arr[0][j];
            if (lastMin > dp[0][j])
            {
                if (lastMin < lastMin2)
                {
                    lastMin2 = lastMin;
                }
                lastMin = dp[0][j];
                lastMinIndex = j;
            }
            else if(lastMin2 > dp[0][j])
            {
                lastMin2 = dp[0][j];
            }
        }
        for (int i = 1; i < m; i++)
        {
            //利用上一行最小的dp以及第二小的dp和对应下标，计算当前行的dp
            //并记录当前行的最小dp和第二小dp，以及对应下标，为下一层循环服务。
            thisMin = MAX_VALUE, thisMin2 = MAX_VALUE;
            for (int j = 0; j < n; j++)
            {
                if (j==lastMinIndex)
                {
                    dp[i][j] = lastMin2 + arr[i][j];
                }
                else
                {
                    dp[i][j] = lastMin + arr[i][j];
                }

                if (thisMin > dp[i][j])
                {
                    //thisMin要被替换，先看看能不能充当thisMin2
                    if (thisMin < thisMin2)
                    {
                        thisMin2 = thisMin;
                    }
                    thisMin = dp[i][j];
                    thisMinIndex = j;
                }
                else if (thisMin2 > dp[i][j])
                {
                    thisMin2 = dp[i][j];
                }
            }
            lastMin = thisMin, lastMin2 = thisMin2, lastMinIndex = thisMinIndex;
        }
        return lastMin;
    }
};