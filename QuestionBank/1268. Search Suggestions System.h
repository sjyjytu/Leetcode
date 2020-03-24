#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	//Runtime: 152 ms, faster than 38.60% of C++ online submissions for Search Suggestions System.
	//Memory Usage : 35.6 MB, less than 100.00 % of C++ online submissions for Search Suggestions System.
	//横着比较
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		int n = products.size();
		int m = searchWord.size();
		sort(products.begin(), products.end());
		vector<bool> oks(n, 1);
		vector<vector<string>>result;
		for (int i = 0; i < m; i++)
		{
			char c = searchWord[i];
			vector<string> tmp;
			for (int j = 0; j < n; j++)
			{
				if (oks[j] && products[j].size()-1>=i && products[j][i] == c)
				{
					if (tmp.size() < 3)
					{
						tmp.push_back(products[j]);
					}
				}
				else
				{
					oks[j] = false;
				}
			}
			result.push_back(tmp);
		}
		return result;
	}

	//Runtime: 64 ms, faster than 61.21% of C++ online submissions for Search Suggestions System.
	//Memory Usage : 36.2 MB, less than 100.00 % of C++ online submissions for Search Suggestions System.
	//竖着比较
	vector<vector<string>> suggestedProducts2(vector<string>& products, string searchWord) {
		int n = products.size();
		int m = searchWord.size();
		sort(products.begin(), products.end());
		vector<int> okUntil(n, 0);
		vector<vector<string>>result;
		for (int i = 0; i < n; i++)
		{
			string curWord = products[i];
			okUntil[i] = curWord.size() - 1;
			for (int j = 0; j < m; j++)
			{
				if (curWord.size()-1 < j || curWord[j] != searchWord[j])
				{
					okUntil[i] = j - 1;
					break;
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			vector<string> tmp;
			for (int j = 0; j < n && tmp.size() < 3; j++)
			{
				if (okUntil[j] >= i)
				{
					tmp.push_back(products[j]);
				}
			}
			result.push_back(tmp);
		}
		return result;
	}

};