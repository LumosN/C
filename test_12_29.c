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
	//1.拷贝结点链到原结点后面，形成每个拷贝结点都链接在原结点的后面
	struct Node* cur = head;
	while (cur != NULL)
	{
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->next = NULL;
		copy->random = NULL;
		copy->val = cur->val;
		//链接：
		copy->next = cur->next;
		cur->next = copy;
		//移动cur
		cur = cur->next->next;
	}
	//2.处理一下拷贝结点的random，拷贝结点的random等于原结点的random的next
	cur = head;
	while (cur != NULL)
	{
		struct Node* copy = cur->next;//copy就是在cur后面的结点
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
	//3.拆解出复制链表（三个指针搞定）
	cur = head;
	struct Node* copyHead = head->next;
	while (cur != NULL)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		//拆分
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