/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
	bool removeNode(ListNode* pNode) {
		// write code here
		if (pNode->next == NULL)
		{
			pNode->next = NULL;
			return false;
		}
		else
		{
			ListNode* pNext = pNode->next;
			pNode->val = pNext->val;

			pNode->next = pNext->next;
			return true;
		}
	}
};