/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	ListNode* root = (ListNode*)malloc(sizeof(ListNode));//Ϊ�˴���ͷ����ͬ�����
	root->next = pHead;
	ListNode* pre = root, *cur = root;//curָ������ӵĽ��
	while (cur != NULL)
	{
		while (cur->next != NULL&&cur->val == cur->next->val)
		{
			cur = cur->next;
		}
		cur = cur->next;
		if (cur != NULL&&cur->next != NULL&&cur->val == cur->next->val)
		{
			continue;//�����¿�ʼѭ��
		}
		pre->next = cur;//����
		pre = pre->next;
	}
	return root->next;
}