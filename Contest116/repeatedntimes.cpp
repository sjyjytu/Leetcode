#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
	int repeatedntimes(vector<int>& a) {
		int tmparray[10000] = { 0 };
		for (int i = 0; i < a.size(); i++)
		{
			tmparray[a[i]]++;
			if (tmparray[a[i]] >= 2)
				return a[i];
		}
	}
};

/*int main()
{
	solution s;
	vector<int> test = { 5,1,5,2,5,3,5,4 };
	cout << s.repeatedntimes(test);
	system("pause");
	return 0;
}*/