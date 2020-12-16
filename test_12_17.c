/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == NULL)
		{
			return NULL;
		}
		ListNode *l1 = (ListNode*)malloc(sizeof(ListNode));
		ListNode *l2 = (ListNode*)malloc(sizeof(ListNode));
		ListNode *cur = pHead;
		int tmp1 = 0, tmp2 = 0;
		ListNode *pl1 = l1, *pl2 = l2;
		while (cur != NULL)
		{
			if (cur->val < x)
			{
				pl1->next = cur;
				pl1 = cur;
			}
			else
			{
				pl2->next = cur;
				pl2 = cur;
			}
			cur = cur->next;
		}
		//最后把l1、l2接到一起
		pl2->next = NULL;
		pl1->next = l2->next;
		return l1->next;
	}
};