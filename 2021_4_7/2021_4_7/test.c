#define _CRT_SECURE_NO_WARNINGS 1
//203.�Ƴ�����Ԫ��
//����һ�������ͷ�ڵ� head ��һ������ val ��
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��

struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;

	while (cur)      //ֻҪcur!=NULL��ѭ��
	{
		struct ListNode* next = cur->next;  //next ��cur����һ�����
		if (cur->val == val)
		{
			if (prev == head)  //cur��ͷ,ֵ�ڵ�һ��
			{
				free(cur);
				head = next;
				cur = next;
			}
			else
			{
				prev->next = next;    //curǰһ������ָ��ָ��cur����һ�����
				free(cur);
				cur = next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}


//206.��ת����
//��תһ��������
//l.����3��ָ�뷭ת
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
	while (n2)  //ֱ��n2Ϊ�ս���ѭ��
	{
		//��ת
		n2->next = n1;

		//����
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//2.ͷ�巨���������½��
//����˼·��ȡԭ�����еĽ��ͷ�嵽�½�㣬Ҫ�ȱ���һ��������һ����ַ����Ȼȡ�����Ҳ�������Ľ��
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* cur = head;
	struct LidtNode* newHead = NULL;
	while (cur)
	{
		struct ListNode* next = NULL;
		next = cur->next;
		cur->next = newHead;
		newHead = cur;
		cur = next;
	}
	return newHead;
}


//876.������м���
//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

//����������м��㣬�򷵻صڶ����м��㡣


//˼·������ָ�룬��ָ��һ������������ָ��һ����һ��������һ��
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* fast = head, *slow = head;
	while (fast && fast->next)  //������ѭ��������
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;   //slow���м���
}
