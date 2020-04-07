#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		priority_queue<int, vector<int>, less<int>> pq;
		vector<int> result;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			pq.push(nums[i]);
		}
		int cur_sum = 0;
		while (sum - cur_sum >= cur_sum)
		{
			int t = pq.top();
			cur_sum += t;
			result.push_back(t);
			pq.pop();
		}
		return result;
	}

	int numSteps(string s) {
		int count = 0;
		int carry_bit = 0;
		for (int i = s.size()-1; i > 0; i--)
		{
			int cur_bit = s[i] - '0';
			switch (carry_bit + cur_bit)
			{
			case 0:
				carry_bit = 0;
				count++;
				break;
			case 1:
				carry_bit = 1;
				count += 2;
				break;
			case 2:
				carry_bit = 1;
				count++;
			default:
				break;
			}
		}
		if (carry_bit)
		{
			count++;
		}
		return count;
	}

	string longestDiverseString(int a, int b, int c) {
		string res = "";
		int A = 0, B = 0, C = 0;
		while (true)
		{
			if ((a >= b && a >= c && A < 2 && a>0) || (B == 2 && a > 0) || (C == 2 && a > 0)) {
				res += 'a';
				a--;
				A++;
				B = 0;
				C = 0;
			}
			else if ((b >= a && b >= c && B < 2 && b>0) || (A == 2 && b > 0) || (C == 2 && b > 0)) {
				res += 'b';
				b--;
				B++;
				A = 0;
				C = 0;
			}
			else if ((c >= a && c >= b && C < 2 && c>0) || (A == 2 && c > 0) || (B == 2 && c > 0)) {
				res += 'c';
				c--;
				C++;
				A = 0;
				B = 0;
			}
			else {
				return res;
			}
		}
	}

	string stoneGameIII(vector<int>& stoneValue) {
		int n = stoneValue.size();
		vector<int> sumUntilEnd(n + 1, 0);
		for (int i = n-1; i >= 0; i--)
		{
			sumUntilEnd[i] = stoneValue[i] + sumUntilEnd[i + 1];
		}
		vector<int> dp(n, 0);
		dp[n - 1] = stoneValue[n - 1];
		if (n == 1)
		{
			return compare(stoneValue[0], 0);
		}
		dp[n - 2] = max(stoneValue[n - 2], sumUntilEnd[n-2]);
		if (n == 2)
		{
			return compare(dp[0], dp[1]);
		}
		dp[n - 3] = max3(stoneValue[n-3] + sumUntilEnd[n-2] - dp[n-2], stoneValue[n-3] + stoneValue[n-2], sumUntilEnd[n-3]);
		for (int i = n-4; i >= 0; i--)
		{
			dp[i] = max3(stoneValue[i] + sumUntilEnd[i + 1] - dp[i + 1],
				stoneValue[i] + stoneValue[i + 1] + sumUntilEnd[i + 2] - dp[i + 2],
				stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + sumUntilEnd[i + 3] - dp[i + 3]);
		}
		int first = dp[0];
		int second = sumUntilEnd[0] - first;
		if (first>second)
		{
			return "Alice";
		}
		else if (first==second)
		{
			return "Tie";
		}
		else
		{
			return "Bob";
		}
	}

	int max3(int a, int b, int c)
	{
		return max(max(a, b), c);
	}

	string compare(int first, int second)
	{
		if (first > second)
		{
			return "Alice";
		}
		else if (first == second)
		{
			return "Tie";
		}
		else
		{
			return "Bob";
		}
	}
};
