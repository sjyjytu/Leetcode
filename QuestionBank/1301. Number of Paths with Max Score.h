#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
#define moduli 1000000007
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<vector<long>>>dp(n,vector<vector<long>>(n, vector<long>(2, 0)));  //第一个记录最大值，第二个记录到达最大值的可能数
        dp[n - 1][n - 1][1] = 1;
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[n - 1][j] == 'X' || dp[n - 1][j + 1][1] == -1)
            {
                dp[n - 1][j][1] = -1;
            }
            else
            {
                dp[n - 1][j][0] = dp[n - 1][j + 1][0] + board[n - 1][j] - '0';
                dp[n - 1][j][1] = dp[n - 1][j + 1][1];
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (board[i][n-1] == 'X' || dp[i+1][n-1][1] == -1)
            {
                dp[i][n - 1][1] = -1;
            }
            else
            {
                dp[i][n - 1][0] = dp[i+1][n - 1][0] + board[i][n - 1] - '0';
                dp[i][n - 1][1] = dp[i + 1][n - 1][1];
            }
        }
        for (int i = n-2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (board[i][j] == 'X')
                {
                    dp[i][j][1] = -1;
                }
                else
                {
                    int max = 0;
                    int possibility = -1;
                    if (dp[i + 1][j + 1][1]!=-1)
                    {
                        max = dp[i + 1][j + 1][0];
                        possibility = dp[i + 1][j + 1][1];
                    }
                    if (dp[i][j + 1][1] != -1)
                    {
                        if (dp[i][j + 1][0] > max)
                        {
                            max = dp[i][j + 1][0];
                            possibility = dp[i][j + 1][1];
                        }
                        else if (dp[i][j + 1][0] == max)
                        {
                            possibility += dp[i][j + 1][1];
                        }
                    }
                    if (dp[i + 1][j][1] != -1)
                    {
                        if (dp[i + 1][j][0] > max)
                        {
                            max = dp[i + 1][j][0];
                            possibility = dp[i + 1][j][1];
                        }
                        else if (dp[i + 1][j][0] == max)
                        {
                            possibility += dp[i + 1][j][1];
                        }
                    }
                    dp[i][j][0] = (board[i][j] - '0' + max) % moduli;
                    dp[i][j][1] = possibility % moduli;
                }
            }
        }
        if (dp[0][0][1]==-1)
        {
            return { 0,0 };
        }
        else
        {
            return { int(dp[0][0][0] + '0' - 'E'), int(dp[0][0][1]) };
        }
    }
};