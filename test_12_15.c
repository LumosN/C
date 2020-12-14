/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (A == NULL)
		{
			return false;
		}
		else if (A->next == NULL)
		{
			return true;
		}
		ListNode* slow = A, *quick = A;
		//1.�ҵ�������м�λ��
		while (quick != NULL&&quick->next != NULL)//ż�������������
		{
			slow = slow->next;//��ָ����һ��
			quick = quick->next->next;//��ָ��������
			//��������ָ���ߵ�β����ָ��պ����м�
		}
		//2.��ת����ĺ�벿��
		ListNode* n1 = slow->next;
		ListNode* n2 = n1->next;
		while (n1 != NULL)
		{
			n1->next = slow;
			slow = n1;
			n1 = n2;
			if (n2 != NULL)
			{
				n2 = n2->next;
			}
		}//����������Ұ벿�ֱ��γ�����slowΪͷ��һ���µĵ�����
		//3.�Ƚ�
		while (A != slow)//���������ߵ��м��ʱ�򣬶������
		{
			if (A->val != slow->val)
			{
				return false;
			}
			else//��ȵ�ʱ�򣬿��ǽ��ż���˳�ѭ��������A->next == slow
			{
				if (A->next == slow)
				{
					return true;
				}
			}
			A = A->next;
			slow = slow->next;
		}
		return true;
	}
};