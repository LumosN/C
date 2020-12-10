/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode*prev = NULL, *cur = head;//prev�������cur��ǰһ�����
	while (cur != NULL)//cur==NULLҲ���ǰ����еĽ�㶼������
	{
		if (cur->val == val)//���ʱ���������
		{
			if (cur == head)//��ͷʱ
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else//����ͷ
			{
				prev->next = cur->next;//����
				free(cur);//�ͷ�
				cur = prev->next;//������������
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}