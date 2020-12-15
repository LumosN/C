/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		//先让快指针先走K步，这样快与慢指针相差K步
		//然后两个一起走，当快走到NULL，慢所指即为所求
		ListNode* quick = pListHead, *slow = pListHead;
		while (k--)
		{
			if (quick == NULL)//说明k的值大于链长
			{
				return NULL;
			}
			quick = quick->next;
		}
		while (quick)
		{
			slow = slow->next;
			quick = quick->next;
		}
		return slow;
	}
};