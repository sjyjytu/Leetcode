#include <vector>

using namespace std;

class Solution {
public:
	//�ݹ����������Գ��ڴ���
	bool canJump1(vector<int>& nums) {
		vector<int> impossible(nums.size());
		return curIndexCanJump(nums, impossible, 0);
	}

	bool curIndexCanJump(vector<int> nums, vector<int> &impossible, int curIndex)
	{
		if (curIndex >= nums.size()-1)
		{
			return true;
		}
		for (int i = 0; i < nums[curIndex]; i++)
		{
			int nextIndex = curIndex + i + 1;
			if (impossible[nextIndex] != 1)
			{
				if (curIndexCanJump(nums, impossible, nextIndex))
				{
					return true;
				}
				else
				{
					impossible[nextIndex] = 1;
				}
			}
		}
		return false;
	}

	//ת��Ϊ��0��������Զ�ܵ��ģ����Ӷ�O��n^2����ʱ��ֻ�����5%����ң�̫������
	bool canJump2(vector<int>& nums) {
		vector<int> canGet(nums.size());
		if (nums.size() > 0)
		{
			canGet[0] = 1;
		}
		else
		{
			return true;
		}
		if (nums.size()==1)
		{
			return true;
		}
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (canGet[i] == 1)
			{
				for (int j = 1; j < nums[i] + 1; j++)
				{
					if (i + j >= nums.size() - 1)
					{
						return true;
					}
					canGet[i + j] = 1;
				}
			}
		}
		return false;
	}

	//���������벻�������������һ�ѣ��򵥵�һ�ƣ��һ���̫����
	//һ������Ҫ�Ľ��ۣ����һ������Ե������֮ǰ�����е㶼���Ե������ֻҪ����Զ�ܵ���Զ
	bool canJump(vector<int>& nums) {
		int max = 0;
		//int n = nums.size();  //���棬�������д�Ļ����ڴ������һ�㣬��������ʱ��ȴ����8ms
		for (int i = 0; i < nums.size() && i <= max; i++)
		{
			if (i+nums[i]>=max)
			{
				max = i + nums[i];
			}
		}
		return max >= nums.size() - 1;
	}
};