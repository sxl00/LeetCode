#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ�������е�����k�����
//����һ����������������е�����k����㡣
//�����������С��k���뷵�ؿա�

ListNode* FindKthToTail(ListNode* pHead, int k) {
	struct ListNode* fast = pHead, *slow = pHead;
	//fast����k��
	while (k--)
	{
		//˵��k��������Ҫ����ô������k�����ǿ�
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;

	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


//��Ŀ���ϲ�������������
//��������������ϲ�Ϊһ���µ� ���� �������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

//ȡС�Ľ��β�嵽������

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}

	struct ListNode* head = NULL, *tail = NULL;

	//��ȡһ��С��ȥ����һ����㣬�������β��
	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}
	else
	{
		head = tail = l2;
		l2 = l2->next;
	}

	while (l1 && l2)  //������û�н�����ѭ��������һ��Ϊ�������ѭ��
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)  //���l1��Ϊ�գ����l1���ӵ�tailָ��ĵ�ַ����
	{
		tail->next = l1;
	}
	if (l2)
	{
		tail->next = l2;
	}
	return head;
}

//����ָ�
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
//��дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

ListNode* partition(ListNode* pHead, int x) {
	ListNode* lessHead, *lessTail, *greaterHead, *greaterTail;
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail->next = NULL;
	greaterTail->next = NULL;

	struct ListNode* cur = pHead;
	while (cur)
	{
		if (cur->val < x)
		{
			lessTail->next = cur;  //β�嵽С��ֵ��������
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = cur;  //β�嵽���ֵ��������
			greaterTail = greaterTail->next;
		}
		cur = cur->next;  //ԭ���������������ƶ�
	}
	//������������
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;   //�ؼ���䣬������һ�������ܻ��γɻ��������ѭ��


	pHead = lessHead->next;
	free(lessHead);
	free(greaterHead);

	return pHead;
}