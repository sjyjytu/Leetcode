#include <string>
#include <unordered_map>

using namespace std;
//2020 01-28-01-29
class Solution {
public:
	unsigned long long _hash[10001];
	unsigned long long _base[10001];
	int base = 26;

	string longestDupSubstring(string S) {
		init(S);
		int left_length = 1;
		int right_length = S.size() - 1;
		int result;
		while (left_length <= right_length)
		{
			int middle_length = (left_length + right_length) / 2;
			int tmp = check(S, middle_length);
			if (tmp != -1)
			{
				left_length = middle_length + 1;
				result = tmp;
			}
			else
			{
				right_length = middle_length - 1;
			}
		}
		left_length--;
		if (left_length <= 0)
		{
			return "";
		}

		return S.substr(result, left_length);
	}

	void init(string S)
	{
		_base[0] = 1;
		_hash[0] = 0;
		for (int i = 1; i <= S.size(); i++)
		{
			_base[i] = _base[i - 1] * base;
			_hash[i] = _hash[i - 1] * base + S[i - 1] - 'a';
		}
	}

	unsigned long long getHash(int lindex, int rindex)
	{
		return _hash[rindex] - _hash[lindex-1] * _base[rindex-lindex+1];
	}

	int check(string S, int length)
	{
		unordered_map<unsigned long long, bool> umap;
		for (int i = 0; i <= S.size()-length; i++)
		{
			unsigned long long tmp = getHash(i + 1, i + length);
			if (umap.find(tmp)==umap.end())
			{
				umap[tmp] = 1;
			}
			else
			{
				return i;
			}
		}
		return -1;
	}
};