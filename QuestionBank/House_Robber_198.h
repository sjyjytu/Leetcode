#include <vector>
#include <algorithm>
using namespace std;
//12.22 从两点写算法写到九点，要吐了。在水easy的路上一去不复返。。。
class Solution {
public:
	int rob(vector<int>& nums) {
		int notRob = 0;
		int rob = 0;
		
		for (int i = 0; i < nums.size(); i++)
		{
			int newRob = notRob + nums[i];  //这样新建一个临时变量比在循环外搞一个变量要快
			notRob = max(notRob, rob);
			rob = newRob;
		}
		return max(rob, notRob);
	}
};