#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string strWithout3a3b(int A, int B) {
		string s = "";
		//construct the worst position: aabaabaabaabaabaa
		int maxInt, minInt;
		if (A >= B)
		{
			maxInt = A;
			minInt = B;
		}
		else
		{
			maxInt = B;
			minInt = A;
		}
		char maxChar = A >= B ? 'a' : 'b';
		char minChar = A<B ? 'a' : 'b';
		while (maxInt>0) {
			if (maxInt>1)
			{
				s += maxChar;
				s += maxChar;
				maxInt -= 2;
			}
			else
			{
				s += maxChar;
				maxInt--;
			}
			if (minInt>0)
			{
				s += minChar;
				minInt--;
			}
		}
		//fill the left b -> aabbaabbaabaabaa
		int index = 0;
		string subS = s;
		while (minInt>0)
		{
			index += subS.find(minChar);//absolute index
			s.insert(s.begin()+index, minChar);
			index += 2;//get to the next begin of subS
			subS = s.substr(index);
			minInt--;
		}
		return s;
	}
};