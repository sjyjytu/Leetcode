#include <vector>
#include <string>
using namespace std;

//12.12 ����ڶ������Ͼ���һ��̫���ˣ��������Ҳ���ߣ�czn˵������㷨�ܾ��������˼
//�����ҷ��ֶ��ύ���β����ڴ�ʹ�ò�һ��������ʱ��Ҳ��һ��������8ms��4ms�������ǲ�������
//���������۾��������·���ִ���Բ���۾�����czn˵�ܴ����Ų��ʺ��ң������˴󴴣����˰�ᣬ������
//������cv����������������������ҵ30w�ǰײ˼ۣ���Ը�ɡ����������ڹ�������������ʦ˵�����������û��ã�
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