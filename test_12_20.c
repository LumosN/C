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
	struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));//�±�ͷ
	newHead->next = head;//�����ϵ�����
	struct ListNode* p = newHead, *q = head; //pָ���±��ͷ��qָ���Ѿ��ź���������β
	struct ListNode* cur = head->next;
	while (cur != NULL)
	{
		if (cur->val >= q->val)//���cur���źõı��β��Ҫ�󣬺���
		{
			q = q->next;
			cur = cur->next;
		}
		else//����Ҫ��ͷ��Ҫ�����λ��
		{
			p = newHead;//�������newHead
			q->next = cur->next;//cur�ó���
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