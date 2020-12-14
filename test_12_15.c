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
		//1.找到链表的中间位置
		while (quick != NULL&&quick->next != NULL)//偶数和奇数的情况
		{
			slow = slow->next;//慢指针走一步
			quick = quick->next->next;//快指针走两步
			//这样，快指针走到尾，慢指针刚好在中间
		}
		//2.反转链表的后半部分
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
		}//这样链表的右半部分便形成了以slow为头的一个新的单链表
		//3.比较
		while (A != slow)//奇数：都走到中间的时候，二者相等
		{
			if (A->val != slow->val)
			{
				return false;
			}
			else//相等的时候，考虑结点偶数退出循环条件：A->next == slow
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