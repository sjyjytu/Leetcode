#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int charsNum[26] = { 0 };
		int result = 0;
		for (int i = 0; i < chars.size(); i++)
		{
			charsNum[chars[i] - 'a'] += 1;
		}
		for (int i = 0; i < words.size(); i++)
		{
			string thisWord = words[i];
			int curCharsNum[26] = { 0 };
			bool thisWordOk = true;
			for (int j = 0; j < thisWord.size(); j++)
			{
				curCharsNum[thisWord[j] - 'a']++;
				if (curCharsNum[thisWord[j] - 'a'] > charsNum[thisWord[j] - 'a'])
				{
					thisWordOk = false;
					break;
				}
			}
			if (thisWordOk)
			{
				result += thisWord.size();
			}
		}
		return result;
	}
};