#include <vector>
#include <algorithm>
using namespace std;
//12.22 ������д�㷨д���ŵ㣬Ҫ���ˡ���ˮeasy��·��һȥ������������
class Solution {
public:
	int rob(vector<int>& nums) {
		int notRob = 0;
		int rob = 0;
		
		for (int i = 0; i < nums.size(); i++)
		{
			int newRob = notRob + nums[i];  //�����½�һ����ʱ��������ѭ�����һ������Ҫ��
			notRob = max(notRob, rob);
			rob = newRob;
		}
		return max(rob, notRob);
	}
};