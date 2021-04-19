#define _CRT_SECURE_NO_WARNINGS 1
//1.复制带随机指针的链表
//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，
//该指针可以指向链表中的任何节点或空节点。

//思路：
//1.拷贝结点链接在原链表结点的后面
//2.处理拷贝结点的random
//3.拷贝结点给解下来，链接到一起

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
	{
		return NULL;
	}
	//1.拷贝结点链接在原链表结点的后面
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
	//2.处理拷贝结点的random
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
	//3.拷贝结点给解下来，链接到一起,恢复原链表
	cur = head;
	struct Node* copyHead, *copyTail;
	copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;

		//尾插
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

//2.删除链表中重复的结点
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

ListNode* deleteDuplication(ListNode* pHead) {
	//没有结点或只有一个结点
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	//起始条件
	struct ListNode* prev = NULL, *cur = pHead, *next = pHead->next;
	//结束条件
	while (next)
	{
		if (cur->val == next->val)
		{
			//删除重复的
			//防止最后一段为null的情况
			while (next && cur->val == next->val) //next往后走，找到跟cur不相等位置
			{
				next = next->next;
			}

			//删掉cur与next之间的结点
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
		else  //重复
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	return pHead;
}

//3.对链表进行插入排序
struct ListNode* insertionSortList(struct ListNode* head){
	//链表为空或只有一个结点
	if (head == NULL || head->next == NULL)
		return head;

	//1、循环的初始条件
	struct ListNode* sortHead = head;
	struct ListNode* cur = head->next;  //找到head后面的结点
	sortHead->next = NULL;

	while (cur)  //2、终止条件
	{
		//3、迭代条件
		struct ListNode* next = cur->next;  //保存下一结点的地址

		//将cur结点插入到前面的有序区间
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
		//下面的if是为了防止c为空，最后插入的值比p还大，此时却插入不进去
		if (p == NULL)
			//头插，只在c前面
		{
			cur->next = c;
			sortHead = cur;
		}
		else     //在 p   c中间插入
		{
			p->next = cur;
			cur->next = c;
		}
		cur = next;
	}
	return sortHead;
}