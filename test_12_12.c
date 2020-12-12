/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* middleNode(struct ListNode* head){
	//����ָ����
	//��ָ������������ָ����һ���������ָ����ָ��Ϊ�м�λ��
	struct ListNode* quick = NULL, *slow = NULL;
	while (quick != NULL || quick->next != NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
	}
	return slow;
}