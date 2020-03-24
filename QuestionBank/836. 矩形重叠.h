#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		int ax1 = rec1[0];
		int ay1 = rec1[1];
		int ax2 = rec1[2];
		int ay2 = rec1[3];
		int bx1 = rec2[0];
		int by1 = rec2[1];
		int bx2 = rec2[2];
		int by2 = rec2[3];
		return abs(ax1 - bx2) < abs(ax2 - ax1 + bx2 - bx1)
			&& abs(ax2 - bx1) < abs(ax2 - ax1 + bx2 - bx1)
			&& abs(ay1 - by2) < abs(ay2 - ay1 + by2 - by1)
			&& abs(ay2 - by1) < abs(ay2 - ay1 + by2 - by1);
	}
};