#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int fc = 0, fr = m - 1;
        while (fc < n && fr >=0)
        {
            int flag = matrix[fr][fc];
            if (target==flag)
            {
                return true;
            }
            else if (target > flag)
            {
                fc++;
            }
            else
            {
                fr--;
            }
        }
        return false;
    }
};
