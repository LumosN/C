#include<stdio.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* reverseList(struct ListNode* head){
	//ͷ�巨��ȡcurͷ�嵽��newHeadΪͷ����������
	struct ListNode *newHead = NULL;
	struct ListNode *cur = head, *next = head->next;
	while (cur != NULL)//��cur==NULLʱ����ѭ��������˵�����еĽ�㶼�����뵽���µĵ������� 
	{
		//ͷ�� 
		cur->next = newHead;
		newHead = cur;
		//next��¼cur���¸�����λ�� 
		cur = next;//cur������ 
		if (next != NULL)
		{
			next = next->next;
		}
	}
	return newHead;
}
