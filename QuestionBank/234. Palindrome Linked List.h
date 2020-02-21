#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

//2020 2-21 15:43
//Runtime: 24 ms, faster than 73.48 % of C++ online submissions for Palindrome Linked List.
//Memory Usage: 12.8 MB, less than 53.45 % of C++ online submissions for Palindrome Linked List.
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	//先找到中节点，然后翻转后半段，不知道为啥，本地过得了，leetcode过不了
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
		{
			return true;
		}
		ListNode* middleNode = head, * lastNode = head;
		while (lastNode->next && lastNode->next->next)
		{
			middleNode = middleNode->next;
			lastNode = lastNode->next->next;
		}
		//middle->post1->post2->post3->last
		//post1、post2、post3, post2->next = post1, post1 = post2, post2 = post3 post3 = post3->next; 
		//middle->post1<-post2 post3->last(middle<-post1)
		ListNode* post1 = middleNode, * post2 = middleNode->next;
		while (post2)
		{
			ListNode* post3 = post2->next;
			post2->next = post1;
			post1 = post2;
			post2 = post3;
		}

		ListNode* l2r = head, *r2l = post1;
		bool result = true;
		while (r2l != middleNode)
		{
			if (l2r->val!=r2l->val)
			{
				result = false;
				break;
			}
			l2r = l2r->next;
			r2l = r2l->next;
		}
		return result;
	}

	bool isPalindrome2(ListNode* head) {
		if (!head || !head->next)
		{
			return true;
		}
		ListNode* middleNode = head, * lastNode = head;
		while (lastNode->next && lastNode->next->next)
		{
			middleNode = middleNode->next;
			lastNode = lastNode->next->next;
		}

		ListNode* last = middleNode->next;
		while (last->next)
		{
			ListNode* tmp = last->next;
			last->next = tmp->next;
			tmp->next = middleNode->next;
			middleNode->next = tmp;
		}

		ListNode* l2m = head;
		bool result = true;
		while (middleNode->next)
		{
			middleNode = middleNode->next;
			if (l2m->val != middleNode->val)
			{
				result = false;
				break;
			}
			l2m = l2m->next;
		}
		return result;
	}
};