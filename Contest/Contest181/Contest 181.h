#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//5364. Create Target Array in the Given Order
class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			res.insert(res.begin() + index[i], nums[i]);
		}
		return res;
	}

	int sumFourDivisors(vector<int>& nums) {
		vector<int> pnums = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313 };
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < pnums.size(); j++)
			{
				if (nums[i] <= pnums[j])
				{
					break;
				}
				if (nums[i] % pnums[j] == 0 
					&& pnums[j] * pnums[j] != nums[i] 
					&& (isPrime(nums[i] / pnums[j]) || nums[i] == pnums[j] * pnums[j] * pnums[j]))
				{
					sum += nums[i] + 1 + pnums[j] + nums[i] / pnums[j];
					break;
				}
			}
		}
		return sum;
	}

	bool isPrime(int n) {
		int i;
		if (n == 1)
		{
			return false;
		}
		for (i = 2; i * i <= n; i++) {
			if ((n % i) == 0) // 如果能被除了1和它本身的数整除，就不是素数
			{
				//cout << i << " " << n / i;
				return false;
			}
		}
		return true; // 是素数
	}

	//5366. Check if There is a Valid Path in a Grid
	bool hasValidPath(vector<vector<int>>& grid) {
		int x = 0, y = 0;
		if (grid[0][0] == 1|| grid[0][0] == 3)
		{
			return checkPath(grid, x, y, Left);
		}
		else if (grid[0][0] == 2 || grid[0][0] == 6)
		{
			return checkPath(grid, x, y, Up);
		}
		else if (grid[0][0] == 4)
		{
			return checkPath(grid, x, y, Down) || checkPath(grid, x, y, Right);
		}
		else
		{
			return false;
		}
		
	}
	enum Direction
	{
		Left, Up, Right, Down
	};

	bool checkPath(vector<vector<int>>& grid, int x, int y, Direction inputDirection)
	{
		Direction outputDirection;
		while (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size())
		{
			if (block(grid[x][y], inputDirection, outputDirection))
			{
				if (x == grid.size() - 1 && y == grid[x].size() - 1)
				{
					return true;
				}
				switch (outputDirection)
				{
				case Solution::Left:
					y -= 1;
					inputDirection = Right;
					break;
				case Solution::Up:
					x -= 1;
					inputDirection = Down;
					break;
				case Solution::Right:
					y += 1;
					inputDirection = Left;
					break;
				case Solution::Down:
					x += 1;
					inputDirection = Up;
					break;
				default:
					break;
				}
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	bool block(int type, Direction inputDirection, Direction &outputDirection)
	{
		switch (type)
		{
		case 1:
			if (inputDirection == Left)
			{
				outputDirection = Right;
			}
			else if (inputDirection == Right)
			{
				outputDirection = Left;
			}
			else
			{
				return false;
			}
			break;
		case 2:
			if (inputDirection == Up)
			{
				outputDirection = Down;
			}
			else if (inputDirection == Down)
			{
				outputDirection = Up;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			if (inputDirection == Left)
			{
				outputDirection = Down;
			}
			else if (inputDirection == Down)
			{
				outputDirection = Left;
			}
			else
			{
				return false;
			}
			break;
		case 4:
			if (inputDirection == Down)
			{
				outputDirection = Right;
			}
			else if (inputDirection == Right)
			{
				outputDirection = Down;
			}
			else
			{
				return false;
			}
			break;
		case 5:
			if (inputDirection == Left)
			{
				outputDirection = Up;
			}
			else if (inputDirection == Up)
			{
				outputDirection = Left;
			}
			else
			{
				return false;
			}
			break;
		case 6:
			if (inputDirection == Up)
			{
				outputDirection = Right;
			}
			else if (inputDirection == Right)
			{
				outputDirection = Up;
			}
			else
			{
				return false;
			}
			break;
		default:
			return false;
			break;
		}
		return true;
	}

	//1392. Longest Happy Prefix
	string longestPrefix(string s) {
		for (int i = s.size() - 1; i > 0; i--)
		{
			int sbegin = s.size() - i;
			bool ok = true;
			for (int j = 0; j < i; j++)
			{
				if (s[j] != s[sbegin+j])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				return s.substr(0, i);
			}
		}
		return "";
	}
};