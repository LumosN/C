/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* middleNode(struct ListNode* head){
	//快慢指针解决
	//快指针走两步，慢指针走一步，最后，慢指针所指即为中间位置
	struct ListNode* quick = NULL, *slow = NULL;
	while (quick != NULL || quick->next != NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
	}
	return slow;
}