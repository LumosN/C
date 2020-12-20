/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));//新表头
	newHead->next = head;//链接上单链表
	struct ListNode* p = newHead, *q = head; //p指向新表的头，q指向已经排好序的链表的尾
	struct ListNode* cur = head->next;
	while (cur != NULL)
	{
		if (cur->val >= q->val)//如果cur比排好的表的尾都要大，后移
		{
			q = q->next;
			cur = cur->next;
		}
		else//否则，要从头找要插入的位置
		{
			p = newHead;//必须得是newHead
			q->next = cur->next;//cur拿出来
			while (p->next != NULL && p->next->val < cur->val)
			{
				p = p->next;
			}
			cur->next = p->next;
			p->next = cur;
			cur = q->next;
		}
	}
	return newHead->next;
}