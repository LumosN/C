/**
* Definition for a Node.
* struct Node {
*     int val;
*     struct Node *next;
*     struct Node *random;
* };
*/

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) return head;
	//1.�����������ԭ�����棬�γ�ÿ��������㶼������ԭ���ĺ���
	struct Node* cur = head;
	while (cur != NULL)
	{
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->next = NULL;
		copy->random = NULL;
		copy->val = cur->val;
		//���ӣ�
		copy->next = cur->next;
		cur->next = copy;
		//�ƶ�cur
		cur = cur->next->next;
	}
	//2.����һ�¿�������random����������random����ԭ����random��next
	cur = head;
	while (cur != NULL)
	{
		struct Node* copy = cur->next;//copy������cur����Ľ��
		if (cur->random != NULL)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = cur->next->next;
	}
	//3.����������������ָ��㶨��
	cur = head;
	struct Node* copyHead = head->next;
	while (cur != NULL)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		//���
		cur->next = next;
		if (next != NULL)
		{
			copy->next = next->next;
		}
		else copy->next = NULL;

		cur = cur->next;
	}
	return copyHead;
}