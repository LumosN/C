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
		//���ÿ�ָ������K��������������ָ�����K��
		//Ȼ������һ���ߣ������ߵ�NULL������ָ��Ϊ����
		ListNode* quick = pListHead, *slow = pListHead;
		while (k--)
		{
			if (quick == NULL)//˵��k��ֵ��������
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