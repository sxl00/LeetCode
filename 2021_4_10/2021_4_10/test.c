#define _CRT_SECURE_NO_WARNINGS 1

//题目：链表中倒数第k个结点
//输入一个链表，输出该链表中倒数第k个结点。
//如果该链表长度小于k，请返回空。

ListNode* FindKthToTail(ListNode* pHead, int k) {
	struct ListNode* fast = pHead, *slow = pHead;
	//fast先走k步
	while (k--)
	{
		//说明k比链表长度要大，那么倒数第k个就是空
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


//题目：合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。 

//取小的结点尾插到新链表

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

	//先取一个小的去做第一个结点，方便后面尾插
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

	while (l1 && l2)  //两个都没有结束就循环，其中一个为空则结束循环
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
	if (l1)  //如果l1不为空，则把l1连接到tail指向的地址后面
	{
		tail->next = l1;
	}
	if (l2)
	{
		tail->next = l2;
	}
	return head;
}

//链表分割
//现有一链表的头指针 ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

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
			lessTail->next = cur;  //尾插到小的值的链表中
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = cur;  //尾插到大的值的链表中
			greaterTail = greaterTail->next;
		}
		cur = cur->next;  //原来链表依次往后移动
	}
	//链接两个链表
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;   //关键语句，若少这一步，可能会形成环，造成死循环


	pHead = lessHead->next;
	free(lessHead);
	free(greaterHead);

	return pHead;
}