#define _CRT_SECURE_NO_WARNINGS 1
//1.���ƴ����ָ�������
//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ��
//��ָ�����ָ�������е��κνڵ��սڵ㡣

//˼·��
//1.�������������ԭ������ĺ���
//2.����������random
//3.�������������������ӵ�һ��

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
	{
		return NULL;
	}
	//1.�������������ԭ������ĺ���
	struct Node* cur = head;
	while (cur)
	{
		struct Node* next = cur->next;
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->val = cur->val;
		cur->next = copy;
		copy->next = next;

		cur = next;
	}
	//2.����������random
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		if (cur->random == NULL)
		{
			copy->random = NULL;
		}
		else
		{
			copy->random = cur->random->next;
		}
		cur = copy->next;
	}
	//3.�������������������ӵ�һ��,�ָ�ԭ����
	cur = head;
	struct Node* copyHead, *copyTail;
	copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;

		//β��
		copyTail->next = copy;
		copyTail = copyTail->next;
		cur->next = next;

		cur = next;
	}

	struct Node* guard = copyHead;
	copyHead = copyHead->next;
	free(guard);

	return copyHead;

}

//2.ɾ���������ظ��Ľ��
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

ListNode* deleteDuplication(ListNode* pHead) {
	//û�н���ֻ��һ�����
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	//��ʼ����
	struct ListNode* prev = NULL, *cur = pHead, *next = pHead->next;
	//��������
	while (next)
	{
		if (cur->val == next->val)
		{
			//ɾ���ظ���
			//��ֹ���һ��Ϊnull�����
			while (next && cur->val == next->val) //next�����ߣ��ҵ���cur�����λ��
			{
				next = next->next;
			}

			//ɾ��cur��next֮��Ľ��
			while (cur != next)
			{
				struct ListNode* del = cur;
				cur = cur->next;
				free(del);
			}

			if (prev == NULL)
			{
				pHead = cur;
			}
			else
			{
				prev->next = cur;
			}
			if (next)
			{
				next = next->next;
			}

		}
		else  //�ظ�
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	return pHead;
}

//3.��������в�������
struct ListNode* insertionSortList(struct ListNode* head){
	//����Ϊ�ջ�ֻ��һ�����
	if (head == NULL || head->next == NULL)
		return head;

	//1��ѭ���ĳ�ʼ����
	struct ListNode* sortHead = head;
	struct ListNode* cur = head->next;  //�ҵ�head����Ľ��
	sortHead->next = NULL;

	while (cur)  //2����ֹ����
	{
		//3����������
		struct ListNode* next = cur->next;  //������һ���ĵ�ַ

		//��cur�����뵽ǰ�����������
		struct ListNode* p = NULL, *c = sortHead;
		while (c)
		{
			if (cur->val < c->val)
			{
				break;
			}
			else   //cur->val > c->val 
			{
				p = c;
				c = c->next;
			}
		}
		//�����if��Ϊ�˷�ֹcΪ�գ��������ֵ��p���󣬴�ʱȴ���벻��ȥ
		if (p == NULL)
			//ͷ�壬ֻ��cǰ��
		{
			cur->next = c;
			sortHead = cur;
		}
		else     //�� p   c�м����
		{
			p->next = cur;
			cur->next = c;
		}
		cur = next;
	}
	return sortHead;
}