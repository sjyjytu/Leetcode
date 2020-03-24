#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int result = 0;
		int curMax = -1;
		for (int i = 0; i < light.size(); i++)
		{
			if (curMax < light[i])
			{
				curMax = light[i];
			}
			if (curMax == i+1)
			{
				result++;
			}
		}
		return result;
	}
};