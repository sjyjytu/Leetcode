#include <vector>
using namespace std;

class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		int layer = 0;
		int count = 1;
		vector<int> result;
		result.push_back(label);
		while (label >= count)
		{
			count <<= 1;
			layer++;
		}
		int layerBegin = count >> 1;
		int labelInLayerIndex = layer & 1 == 1 ? label - layerBegin : 2 * layerBegin - label - 1;
		while (--layer > 0)
		{
			labelInLayerIndex >>= 1;
			layerBegin >>= 1;
			int clabel = layer & 1 == 1 ? layerBegin + labelInLayerIndex : 2 * layerBegin - labelInLayerIndex - 1;
			result.push_back(clabel);
		}
		int n = result.size();
		vector<int> realResult(n);
		for (int i = 0; i < n; i++)
		{
			realResult[i] = result[n - i - 1];
		}
		return realResult;
	}
};