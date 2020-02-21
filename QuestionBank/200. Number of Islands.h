#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

//1-20 11:21-1:22
//Runtime: 8 ms, faster than 99.03 % of C++ online submissions for Number of Islands.
//Memory Usage: 11 MB, less than 55.06 % of C++ online submissions for Number of
//找连通性呗，让我想到了计算机视觉上讲的一个染色算法
//折腾半天，还是得用并查集
class Solution {
public:
	class DisjSet
	{
	private:
		std::vector<int> parent;
		std::vector<int> rank; // 秩
		int set_count;

	public:
		DisjSet(int max_size) : parent(std::vector<int>(max_size)),
			rank(std::vector<int>(max_size, 0)), set_count(max_size)
		{
			for (int i = 0; i < max_size; ++i)
				parent[i] = i;
		}
		int find(int x)
		{
			return x == parent[x] ? x : (parent[x] = find(parent[x]));
		}
		void to_union(int x1, int x2)
		{
			int f1 = find(x1);
			int f2 = find(x2);
			if (f1!=f2)
			{
				if (rank[f1] > rank[f2])
					parent[f2] = f1;
				else
				{
					parent[f1] = f2;
					if (rank[f1] == rank[f2])
						++rank[f2];
				}
				set_count--;
			}
			
		}
		bool is_same(int e1, int e2)
		{
			return find(e1) == find(e2);
		}
		int get_set_count()
		{
			return set_count;
		}
	};

	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		vector<vector<char>> color(grid);
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] != '0')
				{
					if ((i - 1 >= 0 && color[i - 1][j] != '0'))
					{
						color[i][j] = color[i - 1][j];
					}
					else if ((j - 1 >= 0 && color[i][j - 1] != '0'))
					{
						color[i][j] = color[i][j - 1];
					}
					else
					{
						count++;
						color[i][j] = count + '0';
					}
				}
			}
		}
		
		DisjSet ds(count);
		cout << count << endl;
		//合并一下相连的颜色
		for (int i = 0; i < color.size(); i++)
		{
			for (int j = 0; j < color[i].size(); j++)
			{
				if (color[i][j] != '0')
				{
					if (i - 1 >= 0 && color[i - 1][j] != '0' && color[i - 1][j] != color[i][j])
					{
						ds.to_union(color[i - 1][j], color[i][j] - '1');
					}
					if (j - 1 >= 0 && color[i][j - 1] != '0' && color[i][j - 1] != color[i][j])
					{
						ds.to_union(color[i][j - 1] - '1', color[i][j] - '1');
					}
				}
			}
		}
		return ds.get_set_count();
	}
};