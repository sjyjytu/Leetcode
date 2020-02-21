#include <vector>
using namespace std;

//12.05夜，周四，因为前几天打球眼镜被砸坏了还没去配，因此今晚欲打球而不得，郁郁写下此题
//10：05毕，还没吃饭，饿死了！
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> have_select(n);
		for (int i = 0; i < n; i++)
		{
			have_select[i] = 0;
		}
		vector<vector<int>> result;
		if (k <= 0)
		{
			return result;
		}
		select_one(result, have_select, 0, k);
		return result;
	}

	void select_one(vector<vector<int>> &result, vector<int> have_select, int begin, int k)
	{
		//有两种方案，一个是数组大小不变，用值为0或1来表示有无
		//另一个是就不断地增加和减少数组的元素
		//各有利弊吧
		//每次选都只往后选，避免重复，如果不够了，直接返回
		for (int i = begin; i < have_select.size()-k+1; i++)
		{
			if (have_select[i]==0)
			{
				//选择i
				have_select[i] = 1;
				if (k > 1)
				{
					select_one(result, have_select, i+1, k - 1);
				}
				else
				{
					vector<int> one_result;
					for (int j = 0; j < have_select.size(); j++)
					{
						if (have_select[j]==1)
						{
							one_result.push_back(j+1);
						}
					}
					result.push_back(one_result);
				}
				have_select[i] = 0;
			}
		}
	}
};