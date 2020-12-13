/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//先求出两个链表的长度
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode *tmpa = headA, *tmpb = headB;
	int l1 = 0, l2 = 0;
	while (tmpa != NULL)
	{
		l1++;
		tmpa = tmpa->next;
	}
	while (tmpb != NULL)
	{
		l2++;
		tmpb = tmpb->next;
	}
	tmpa = headA, tmpb = headB;
	//让长的那条先走 二者长度差 步
	if (l1 > l2)
	{
		int l = l1 - l2;
		while (l--)
		{
			tmpa = tmpa->next;
		}
	}
	else
	{
		int l = l2 - l1;
		while (l--)
		{
			tmpb = tmpb->next;
		}
	}
	//然后再一起遍历，一起走
	while (tmpa != NULL && tmpb != NULL)
	{
		if (tmpa == tmpb)
		{
			return tmpa;
		}
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	return NULL;
}