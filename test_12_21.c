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
	ListNode* root = (ListNode*)malloc(sizeof(ListNode));//为了处理开头就相同的情况
	root->next = pHead;
	ListNode* pre = root, *cur = root;//cur指向待链接的结点
	while (cur != NULL)
	{
		while (cur->next != NULL&&cur->val == cur->next->val)
		{
			cur = cur->next;
		}
		cur = cur->next;
		if (cur != NULL&&cur->next != NULL&&cur->val == cur->next->val)
		{
			continue;//再重新开始循环
		}
		pre->next = cur;//链接
		pre = pre->next;
	}
	return root->next;
}