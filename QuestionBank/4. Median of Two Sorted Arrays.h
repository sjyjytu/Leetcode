#include <vector>
#include <algorithm>
using namespace std;
//12.18 ֮ǰ���������Ĵ𰸣����ڿ��ܲ��ܸ��ֳ���
//���ˣ�����ɹ��ˣ�10:00-13:03 98%
class Solution {
public:
	//��Ϊ�������鳤�Ȳ�һ�������Ծ��ǻ�Ϊ�ҵ�K�����
	//�ֱ���A��B����K/2������Ƚϣ������������ȡ���һ����
	//С����һ������������ǰ��ģ��������Լ���
	//��Ϊ��K���������Ҫ��K-1�����󣬶�������һ�����������ܱ�K-1������
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
