#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
		unordered_set<string> result;
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (words[i].size()<words[j].size())
				{
					if (words[j].find(words[i])!=string::npos)
					{
						result.insert(words[i]);
					}
				}
				else if (words[i].size() == words[j].size())
				{
					if (words[j] == words[i])
					{
						result.insert(words[i]);
					}
				}
				else
				{
					if (words[i].find(words[j]) != string::npos)
					{
						result.insert(words[j]);
					}
				}
			}
		}
		vector<string> vec;
		vec.assign(result.begin(), result.end());
		return vec;
    }

	vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> result(queries.size(),0);
		vector<int> pos(m+1, 0);
		for (int i = 1; i < m+1; i++)
		{
			pos[i] = i-1;
		}
		for (int i = 0; i < queries.size(); i++)
		{
			int qnum = queries[i];
			int oldPos = pos[qnum];
			result[i] = oldPos;
			pos[qnum] = 0;
			for (int j = 1; j < m+1; j++)
			{
				if (j!= qnum&&pos[j]<oldPos)
				{
					pos[j]++;
				}
			}
		}
		return result;
	}

	string entityParser(string text) {
		string result = "";
		int n = text.size();
		for (int i = 0; i < n; i++)
		{
			if (text[i]=='&')
			{
				if (i+3<n)
				{
					if (text[i + 1]=='g' && text[i + 2] == 't' && text[i + 3] == ';')
					{
						result += '>';
						i += 3;
						continue;
					}
					else if (text[i + 1] == 'l' && text[i + 2] == 't' && text[i + 3] == ';')
					{
						result += '<';
						i += 3;
						continue;
					}
				}
				if (i + 4 < n)
				{
					if (text[i + 1] == 'a' && text[i + 2] == 'm' && text[i + 3] == 'p' && text[i + 4] == ';')
					{
						result += '&';
						i += 4;
						continue;
					}
				}
				if (i + 5 < n)
				{
					if (text[i + 1] == 'q' && text[i + 2] == 'u' && text[i + 3] == 'o' && text[i + 4] == 't' && text[i + 5] == ';')
					{
						result += '"';
						i += 5;
						continue;
					}
					else if (text[i + 1] == 'a' && text[i + 2] == 'p' && text[i + 3] == 'o' && text[i + 4] == 's' && text[i + 5] == ';')
					{
						result += '\'';
						i += 5;
						continue;
					}
				}
				if (i + 6 < n)
				{
					if (text[i + 1] == 'f' && text[i + 2] == 'r' && text[i + 3] == 'a' && text[i + 4] == 's' && text[i + 5] == 'l' && text[i + 6] == ';')
					{
						result += '/';
						i += 6;
						continue;
					}
				}
			}
			result += text[i];
		}
		return result;
	}

	int numOfWays(int n) {
		vector<vector<long>>dp(n, vector<long>(2, 0));
		dp[0][0] = 6;
		dp[0][1] = 6;
		long residue = 1e9 + 7;
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = (3 * dp[i - 1][0] + 2 * dp[i - 1][1]) % residue;
			dp[i][1] = (2 * dp[i - 1][0] + 2 * dp[i - 1][1]) % residue;
		}
		return (dp[n - 1][0] + dp[n - 1][1]) % residue;
	}
};