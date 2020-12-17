/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head) {
	//快慢指针 - 判断是否套圈，如果成环，快指针必定会套圈追上慢指针
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