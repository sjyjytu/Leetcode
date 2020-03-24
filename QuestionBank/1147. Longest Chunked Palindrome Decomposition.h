#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
//"ghiabcdefhelloadamhelloabcdefghi"
class Solution {
public:
	int longestDecomposition(string text) {
		int result = 0;
		int n = text.size();
		int leftBeginIndex = 0;
		int rightBeginIndex = n - 1;
		//漏了"a"这种情况
		//rightBeginIndex = n-leftBeginIndex-curLen
		int curLen = 1;
		while (leftBeginIndex + curLen - 1 < n - leftBeginIndex - curLen)
		{
			//找到最小匹配就结束
			string s1 = text.substr(leftBeginIndex, curLen);
			string s2 = text.substr(n - leftBeginIndex - curLen, curLen);
			if (s1 == s2)
			{
				leftBeginIndex += curLen;
				curLen = 1;
				result+=2;
			}
			else
			{
				curLen++;
			}
		}
		if (leftBeginIndex <= (n-1)/2)
		{
			result++;
		}
		return result;
	}
};