#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int gcd(int a, int b)
	{
		if (a > b)
			return gcd(b, a);
		if (a == 0)
			return b;
		if (b % a != 0)
			return gcd(b - a, a);
		return a;
	}
    bool canMeasureWater(int x, int y, int z) {
		if (x+y<z)
		{
			return false;
		}
		if (x==z||y==z||x+y==z)
		{
			return true;
		}
		return z % gcd(x, y) == 0;
    }
};