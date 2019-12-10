#pragma once
#include<vector>
#include<queue>
#include<map>
using namespace std;
//12-10 10��00pm �Һòˣ������д�˺þúþúü���Сʱ��
class Solution {
public:
	//�ȽϺ���ľ��������ѣ����ǣ����������س�ʱ�ˡ�����
	//���ǲο���discuss��trick��רҵ��˵�Ǽ�֦����������������С��i+1����׼ȷ��Ӧ���Ǹ���i+1�����ͳ�100%�ˡ�
	bool canCross(vector<int>& stones) {
		if (stones[1]!=1)
		{
			return false;
		}
		for (int i = 0; i < stones.size()-1; i++)
		{
			if (stones[i+1] - stones[i] > i+1)
			{
				return false;
			}
		}
		return tryJump(stones, 1, 1);
	}

	int have_next_stone(vector<int>& stones, int begin_index, int step, int expect_pos)
	{
		int n = stones.size();
		for (int i = begin_index + 1; i < begin_index + step + 1 && i < n; i++)
		{
			if (stones[i]==expect_pos)
			{
				return i;
			}
			if (stones[i]>expect_pos)
			{
				return 0;
			}
		}
		return 0;
	}

	bool tryJump(vector<int>& stones, int i, int k)
	{
		if (i > stones.size()-1)
		{
			return false;
		}
		if (i == stones.size()-1)
		{
			return true;
		}
		for (int step = k+1; step >= (k - 1 > 0 ? k - 1 : 1); step--)
		{
			int next_pos = stones[i] + step;
			int next_pos_index;
			if ((next_pos_index=have_next_stone(stones, i, step, next_pos)))
			{
				if (tryJump(stones, next_pos_index, step))
				{
					return true;
				}
			}
		}
		return false;
	}

	//���ѣ���ʱ��Ϊ�˸�czn��5��Ǯд�ģ������Ҳû����~~
	bool canCross2(vector<int>& stones) {
		if (stones[1] != 1)
		{
			return false;
		}
		int n = stones.size();
		if (n==2)
		{
			return true;
		}
		queue<pair<int, int>>to_search;
		to_search.push(make_pair(1, 1));
		
		while (!to_search.empty())
		{
			pair<int, int> cur = to_search.front();
			to_search.pop();
			int index = cur.first;
			int step = cur.second;
			for (int next_step = (step-1>0?step-1:1); next_step < step+2; next_step++)
			{
				int destination = stones[index] + next_step;
				for (int i = index; i < index + next_step + 1 && i < n; i++)
				{
					if (stones[i] == destination)  //������ʯͷ����
					{
						if (i == n - 1)  //������ʯͷ�����յ�
						{
							return true;
						}
						to_search.push(make_pair(i, next_step));
					}
					else if (stones[i] > destination)  //������ʯͷ������
					{
						break;
					}
				}
			}		
		}
		return false;
	}
};