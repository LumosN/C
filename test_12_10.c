#include<stdio.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* reverseList(struct ListNode* head){
	//头插法：取cur头插到以newHead为头的新链表中
	struct ListNode *newHead = NULL;
	struct ListNode *cur = head, *next = head->next;
	while (cur != NULL)//当cur==NULL时，即循环结束，说明所有的结点都被插入到了新的单链表中 
	{
		//头插 
		cur->next = newHead;
		newHead = cur;
		//next记录cur的下个结点的位置 
		cur = next;//cur往下走 
		if (next != NULL)
		{
			next = next->next;
		}
	}
	return newHead;
}
