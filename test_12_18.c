/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head) {
	//����ָ�� - �ж��Ƿ���Ȧ������ɻ�����ָ��ض�����Ȧ׷����ָ��
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	struct ListNode* slow = head, *fast = head->next;
	while (slow != fast)
	{
		if (fast == NULL || fast->next == NULL)
		{
			return false;
		}
		if (slow == NULL)
		{
			return false;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}