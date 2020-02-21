#include <iostream>

using namespace std;

//12.09 7��00-8��13������Ů���벻�����е��ѹ�
class Solution {
public:
	//�ҷ�ת�ַ����е������ͬ�ַ�����������ʱ200ms��ֻ����22%���û���������
	string longestPalindrome(string s) {
		//��תһ��
		int n = s.size();
		string rs = s;
		for (int i = 0; i < n; i++)
		{
			rs[i] = s[n - 1 - i];
		}

		int maxLenth = 1;
		int result_begin = 0;
		for (int b1 = 0; b1 < n; b1++)
		{
			for (int b2 = 0; b2 < n - b1; b2++)
			{
				int len = n - b1 - b2;
				if (len > maxLenth)
				{
					bool ok = true;
					for (int i = 0; i < len; i++)
					{
						if (s[b1 + i] != rs[b2 + i])
						{
							ok = false;
							break;
						}
					}
					if (ok)
					{
						maxLenth = len;
						result_begin = b1;
					}
				}
				else
				{
					break;
				}
			}
		}
		return s.substr(result_begin, maxLenth);
	}

	//������չ��������ʱ��12ms������87%
	string longestPalindrome2(string s) {
		if (s.size() <= 1)
		{
			return s;
		}
		int maxLength = 0;
		int resultLeft, resultRight;
		for (int mid = 0; mid < s.size()-1; mid++)
		{
			int left = mid - 1;
			int right = mid + 1;
			while (s[mid] == s[right])
			{
				right++;
			}
			while (left >= 0 && right < s.size() && s[left] == s[right])
			{
				left--;
				right++;
			}
			int result = right - left - 1;
			if (result > maxLength)
			{
				maxLength = result;
				resultLeft = left;
				resultRight = right;
			}
		}
		return s.substr(resultLeft + 1, resultRight - resultLeft - 1);
	}
};