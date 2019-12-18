#include <vector>
#include <algorithm>
using namespace std;
//12.18 之前看了这道题的答案，现在看能不能复现出来
//好了，总算成功了，10:00-13:03 98%
class Solution {
public:
	//因为两个数组长度不一样，所以就是化为找第K大的数
	//分别在A、B中找K/2大的数比较（如果不够长就取最后一个）
	//小的那一个，就舍弃它前面的（包括它自己）
	//因为第K大的数就是要比K-1个数大，而舍弃那一段数都不可能比K-1个数大
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int mn = nums1.size() + nums2.size();
		if (mn % 2 == 0)
		{
			return (findKMaxIndex(nums1, nums2, 0, 0, mn / 2)
				+ findKMaxIndex(nums1, nums2, 0, 0, mn / 2 + 1)) / 2.0;
		}
		else
		{
			return findKMaxIndex(nums1, nums2, 0, 0, mn / 2 + 1);
		}
	}

	int findKMaxIndex(vector<int>& nums1, vector<int>& nums2,
		int leftA, int leftB, int K)
	{
		int sizeA = nums1.size(), sizeB = nums2.size();
		if (leftA >= sizeA)
		{
			return nums2[leftB + K - 1];
		}
		else if (leftB >= sizeB)
		{
			return nums1[leftA + K - 1];
		}
		if (K == 1)
		{
			return min(nums1[leftA], nums2[leftB]);
		}
		int a = K / 2, b = (K + 1) / 2;
		if (a + leftA > sizeA)
		{
			a = sizeA - leftA;
			b = K - a;
		}
		else if (b + leftB > sizeB)
		{
			b = sizeB - leftB;
			a = K - b;
		}
		int rA = leftA + a - 1, rB = leftB + b - 1;
		if (nums1[rA] > nums2[rB])
		{
			return findKMaxIndex(nums1, nums2, leftA, rB + 1, K - b);
		}
		else
		{
			return findKMaxIndex(nums1, nums2, rA + 1, leftB, K - a);
		}
	}
};
