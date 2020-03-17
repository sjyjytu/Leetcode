#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string compressString(string S) {
		if (S == "")
		{
			return S;
		}
		string res;
		char pre_char = S[0];
		int begin_index = 0;
		int count = 1;
		for (int i = 1; i < S.size(); i++)
		{
			if (S[i]==pre_char)
			{
				count++;
			}
			else
			{
				res += pre_char;
				res += to_string(count);
				pre_char = S[i];
				begin_index = i;
				count = 1;
			}
		}
		res += pre_char;
		res += to_string(count);
		return res.size() < S.size() ? res : S;
	}

};