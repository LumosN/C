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
	if (head == NULL || head->next == NULL) //�ж�ͷ�ǲ��ǿգ������ǲ���ֻ��һ�����
	{
		return head;
	}
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
	//n3Ϊ��¼n2֮��Ľ���ַ
	while (n2 != NULL)
	{
		n2->next = n1;//��ת����
		n1 = n2;// ���� �ƶ�
		n2 = n3;
		if (n3 != NULL)//����Ҫ�ж�һ��n3�ǲ���Ϊ�գ�����n3->next��Ƿ�����
		{
			n3 = n3->next;
		}
	}
	head = n1;//n1�����µ�ͷ��
	return head;
}