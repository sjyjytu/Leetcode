#include <vector>
using namespace std;

//12.05ҹ�����ģ���Ϊǰ��������۾����һ��˻�ûȥ�䣬��˽�������������ã�����д�´���
//10��05�ϣ���û�Է��������ˣ�
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
		//�����ַ�����һ���������С���䣬��ֵΪ0��1����ʾ����
		//��һ���ǾͲ��ϵ����Ӻͼ��������Ԫ��
		//�������װ�
		//ÿ��ѡ��ֻ����ѡ�������ظ�����������ˣ�ֱ�ӷ���
		for (int i = begin; i < have_select.size()-k+1; i++)
		{
			if (have_select[i]==0)
			{
				//ѡ��i
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