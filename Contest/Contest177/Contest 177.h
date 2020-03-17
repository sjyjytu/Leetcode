#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
	int daysBetweenDates(string date1, string date2) {
		int year1 = stoi(date1.substr(0, 4));
		int mon1 = stoi(date1.substr(5, 2));
		int day1 = stoi(date1.substr(8, 2));
		int year2 = stoi(date2.substr(0, 4));
		int mon2 = stoi(date2.substr(5, 2));
		int day2 = stoi(date2.substr(8, 2));
		return abs(dayFrom1970_01_01(year2, mon2, day2) - dayFrom1970_01_01(year1, mon1, day1));
	}

	int dayFrom1970_01_01(int year, int mon, int day)
	{
		int result = 0;
		int _years = year - 1970;
		for (int i = 0; i < _years; i++)
		{
			result += 365;
			if (((1970+i) % 4 == 0 && (1970 + i) % 100 != 0)|| (1970 + i)%400==0)
			{
				result += 1;
			}
		}
		int _mons = mon - 1;
		for (int i = 0; i < _mons; i++)
		{
			switch (i+1)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				result += 31;
				break;
			case 2:
				result += ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
				break;
			default:
				result += 30;
				break;
			}
		}
		result += day - 1;
		return result;
	}
};

class Solution3 {
public:
	vector<int> closestDivisors(int num) {
		vector<int> result = { 1, num + 1 };
		int minDistance = num;
		for (int i = 0; i < 2; i++)
		{
			int testNum = num + i + 1;
			for (int j = int(sqrt(testNum)); j > 1; j--)
			{
				if (testNum % j == 0)
				{
					int nj = testNum / j;
					if (nj - j < minDistance)
					{
						minDistance = nj - j;
						result[0] = j;
						result[1] = nj;
						break;
					}
				}
			}
		}
		return result;
	}
};

class Solution4 {
public:
	struct Node
	{
		int sum;
		unordered_set<int> isExcluded;
		Node(int _sum)
		{
			sum = _sum;
		}
		Node(int _sum, unordered_set<int> _isExcluded)
		{
			sum = _sum;
			isExcluded = _isExcluded;
		}
	};

	string largestMultipleOfThree(vector<int>& digits) {
		sort(digits.begin(), digits.end());
		int sum = 0;
		int n = digits.size();
		if (digits[n-1]==0)
		{
			//[0, 0, 0, 0, 0, 0]
			return "0";
		}
		string result = "";
		for (int i = 0; i < n; i++)
		{
			sum += digits[i];
		}
		//用广搜，排除0位到n-1位
		vector<bool> isExcluded(n, 0);
		queue<Node> q;
		q.push(Node(sum));
		while (!q.empty())
		{
			Node node = q.front();
			q.pop();
			if (node.sum % 3 == 0)
			{
				for (int i = n-1; i >= 0; i--)
				{
					if (node.isExcluded.count(i)==0)
					{
						result += digits[i]+'0';
					}
				}
				break;
			}
			else
			{
				for (int i = 0; i < digits.size(); i++)
				{
					if (node.isExcluded.count(i)==0)
					{
						Node newNode(node.sum - digits[i], node.isExcluded);
						newNode.isExcluded.insert(i);
						q.push(newNode);
					}
				}
			}
		}
		return result;
	}
};

//其实不必搜，大可有迹可循的求解，把所有数字放到0，1，2的口袋中，结果多了多少，就扔掉对应口袋中的一个就行
//所谓对应口袋，就是1和2而已，0不用管，如果其中一个口袋没有？那两1就是2，俩2就是1
class Solution4_2 {
public:
	struct Pocket
	{
		int count;
		int minDigitIndex1;
		int minDigitIndex2;
		Pocket()
		{
			count = 0;
		}
	};

	string largestMultipleOfThree(vector<int>& digits) {
		vector<Pocket> pockets(3, Pocket());
		int sum = 0;
		int n = digits.size();
		sort(digits.begin(), digits.end());
		if (digits[n - 1] == 0)
		{
			//[0, 0, 0, 0, 0, 0]
			return "0";
		} 
		for (int i = 0; i < n; i++)
		{
			int index = digits[i] % 3;
			pockets[index].count++;
			if (pockets[index].count == 1)
			{
				pockets[index].minDigitIndex1 = i;
			}
			else if (pockets[index].count == 2)
			{
				pockets[index].minDigitIndex2 = i;
			}
			sum += digits[i];
		}
		string result = "";
		if (sum % 3 == 0)
		{
			for (int i = n - 1; i >= 0; i--)
			{
				result += digits[i] + '0';
			}
		}
		else
		{
			if (pockets[sum % 3].count > 0)
			{
				for (int i = n - 1; i >= 0; i--)
				{
					if (i != pockets[sum % 3].minDigitIndex1)
					{
						result += digits[i] + '0';
					}
				}
			}
			else if (pockets[3 - sum % 3].count >= 2)
			{
				for (int i = n - 1; i >= 0; i--)
				{
					if (i != pockets[3 - sum % 3].minDigitIndex1 && i != pockets[3 - sum % 3].minDigitIndex2)
					{
						result += digits[i] + '0';
					}
				}
			}
		}
		return result;
	}
};