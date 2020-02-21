#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Solution {
public:
	static bool compare(string s1, string s2)
	{
		return s1.size() < s2.size();
	}

	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), compare);
		int result = 0;
		unordered_map<string, int> dp;
		for (string word : words)
		{
			int best = 1;
			for (int i = 0; i < word.size(); i++)
			{
				string tmp = word.substr(0, i) + word.substr(i + 1);
				if (dp[tmp] + 1 > best)
				{
					best = dp[tmp] + 1;
				}
			}
			result = max(best, result);
			dp[word] = best;
		}
		return result;
	}
};