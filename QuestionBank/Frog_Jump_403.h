#pragma once
#include<vector>
#include<queue>
#include<map>
using namespace std;
//12-10 10：00pm 我好菜，这道题写了好久好久好几个小时。
class Solution {
public:
	//比较好想的就是用深搜，但是，不负众望地超时了。。。
	//但是参考了discuss的trick（专业来说是剪枝），相邻两个不能小于i+1（更准确地应该是根号i+1），就超100%了。
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

	//广搜，超时，为了跟czn赌5块钱写的，结果他也没给我~~
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
					if (stones[i] == destination)  //想跳的石头存在
					{
						if (i == n - 1)  //想跳的石头就是终点
						{
							return true;
						}
						to_search.push(make_pair(i, next_step));
					}
					else if (stones[i] > destination)  //想跳的石头不存在
					{
						break;
					}
				}
			}		
		}
		return false;
	}
};