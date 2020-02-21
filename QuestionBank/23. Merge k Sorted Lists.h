#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
//12.19 18:27 瞬间想到的是两两合并，复杂度是O(logk * 2n/k)，差不多是O(n)
//19:27 哇整整写了一个小时，只打赢34%， 内存6%
//19:47 改进了merge2Lists算法，91% 76%
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size()==0)
		{
			return NULL;
		}
		vector<ListNode*> result = lists;
		vector<ListNode*> help;
		while (result.size() > 1)
		{
			int i = 0;
			for (; i < result.size() - 1; i += 2)
			{
				help.push_back(merge2Lists(result[i], result[i + 1]));
			}
			if (i == result.size() - 1)
			{
				help.push_back(result[i]);
			}
			result = help;
			help.clear();
		}
		return result[0];
	}

	ListNode* merge2Lists(ListNode* list1, ListNode* list2)
	{
		ListNode* result_head, *result_tail;
		result_head = result_tail = new ListNode(0);
		ListNode* move1 = list1;
		ListNode* move2 = list2;
		while (move1 != NULL && move2 != NULL)
		{
			if (move1->val <= move2->val)
			{
				result_tail->next = new ListNode(move1->val);
				result_tail = result_tail->next;
				move1 = move1->next;
			}
			else
			{
				result_tail->next = new ListNode(move2->val);
				result_tail = result_tail->next;
				move2 = move2->next;
			}
		}
		if (move1 != NULL)
		{
			result_tail->next = move1;
		}
		if (move2 != NULL)
		{
			result_tail->next = move2;
		}
		return result_head->next;
	}

	ListNode* merge2Lists2(ListNode* list1, ListNode* list2) 
	{
		if (list1==NULL)
		{
			return list2;
		}
		if (list2==NULL)
		{
			return list1;
		}
		ListNode* result;
		ListNode* move;
		ListNode* flag;
		if (list1->val <= list2->val)
		{
			result = list1;
			move = list1;
			flag = list2;
		}
		else
		{
			result = list2;
			move = list2;
			flag = list1;
		}
		int val = flag->val;
		while (move->next != NULL)
		{
			if (move->next->val <= val)
			{
				move = move->next;
			}
			else
			{
				ListNode* tmp = move->next;
				move->next = flag;
				move = move->next;
				flag = tmp;
				val = flag->val;
			}
		}
		move->next = flag;
		return result;
	}
};