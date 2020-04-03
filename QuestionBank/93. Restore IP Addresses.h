#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		search(result, s, "", 0, 1);
		return result;
	}

	void search(vector<string>& result, string &s, string cur_result, int index, int depth)
	{
		if (depth == 4)
		{
			string cur_s = s.substr(index);
			if (cur_s.size() > 1 && cur_s[0] == '0')
			{
				return;
			}
			int num = atoi(cur_s.c_str());
			if (num >= 0 && num < 256)
			{
				result.push_back(cur_result + "." + cur_s);
			}
			return;
		}

		for (int len = 0; len < min(3, int(s.size())-index-(4-depth)); len++)
		{
			string cur_s = s.substr(index, len+1);
			if (cur_s.size() > 1 && cur_s[0] == '0')
			{
				continue;
			}
			int num = atoi(cur_s.c_str());
			if (num >= 0 && num < 256)
			{
				if (depth==1)
				{

					search(result, s, cur_s, index + len + 1, depth + 1);
				}
				else
				{
					search(result, s, cur_result + "." + cur_s, index + len + 1, depth + 1);
				}
			}
		}
	}
};