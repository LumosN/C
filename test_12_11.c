/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode*prev = NULL, *cur = head;//prev保存的是cur的前一个结点
	while (cur != NULL)//cur==NULL也就是把所有的结点都遍历完
	{
		if (cur->val == val)//相等时有两种情况
		{
			if (cur == head)//在头时
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else//不在头
			{
				prev->next = cur->next;//跳过
				free(cur);//释放
				cur = prev->next;//继续在它后面
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