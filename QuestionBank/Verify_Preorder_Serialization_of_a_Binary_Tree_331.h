#include <vector>
#include <string>
using namespace std;

//12.12 今天第二道，毕竟第一道太低了，不过这道也不高，czn说这道题算法很精妙很有意思
//不过我发现多提交几次不仅内存使用不一样，运行时间也不一样，还是8ms和4ms的区别还是不纠结了
//今天配了眼镜，尝试新风格（又大又圆的眼镜），czn说很蠢看着不适合我；讨论了大创，开了班会，结束后
//讨论了cv，还聊了人生，本科生毕业30w是白菜价？但愿吧。回来还终于鼓起勇气和孙老师说鸽了她，还好还好！
class Solution {
public:
	bool isValidSerialization(string preorder) {
		vector<int> pocket(preorder.size()/2+1);
		int top_index = -1;
		int i = 0;
		while (i < preorder.size())
		{
			for (;i  < preorder.size(); i++)
			{
				if (preorder[i]==',')
				{
					break;
				}
			}
			if (preorder[i-1] != '#')
			{
				pocket[++top_index] = 2;
			}
			else
			{
				pocket[++top_index] = 0;
				while (pocket[top_index] == 0)
				{
					top_index--;
					if (top_index < 0)
					{
						return i > preorder.size() - 1;
					}
					pocket[top_index] = pocket[top_index] - 1;
				}
			}
			i++;
		}
			
		return top_index < 0;
	}
};