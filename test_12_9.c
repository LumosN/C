/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//1->2->3->4->5->NULL
//NULL<-1<-2<-3<-4<-5
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL) //判断头是不是空，或者是不是只有一个结点
	{
		return head;
	}
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
	//n3为记录n2之后的结点地址
	while (n2 != NULL)
	{
		n2->next = n1;//反转过程
		n1 = n2;// 迭代 移动
		n2 = n3;
		if (n3 != NULL)//必须要判断一下n3是不是为空，否则n3->next会非法访问
		{
			n3 = n3->next;
		}
	}
	head = n1;//n1就是新的头了
	return head;
}