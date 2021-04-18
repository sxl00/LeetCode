#define _CRT_SECURE_NO_WARNINGS 1
//题目一：
//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，
//判断其是否为回文结构。

//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。
//保证链表长度小于等于900。

//测试样例：1->2->2->1
//返回：true

//思路：先找中间结点，使后半部分逆置，最后比较

//先找中间结点
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* fast = head, *slow = head;
	//struct ListNode* cur = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//逆置后半部分，也是反转链表
//后半部分逆置
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* newHead = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newHead;
		newHead = cur;

		cur = next;
	}
	return newHead;
	//      struct ListNode* cur = head;
	//      struct ListNode* newHead = NULL;
	// 	    while (cur)
	//   	{
				//cur->next改变了指向的对象，指向newHead,newHead下一次指向的是NULL
	// 	        cur->next = newHead;
	// 	    	newHead = cur;

	// 		    cur = cur->next;
	// 	    }
	//      	return newHead;
}
//比较
bool chkPalindrome(ListNode* A)
{
	struct ListNode* mid = middleNode(A);
	struct ListNode* rHead = reverseList(mid);

	while (A && rHead)
	{
		if (A->val != rHead->val)
		{
			return false;
		}
		else
		{
			A = A->next;
			rHead = rHead->next;
		}
	}
	return true;
}


//题目二：
//编写一个程序，找到两个单链表相交的起始节点。
//1.判断是否相交
//2.相交求交点
//拿结点的地址相比，而不是值相比（判断尾指针是否相同）
//计算出两个链表的长度，让长的链表先走差距步
//再同时走，第一个相同的结点，就是交点

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	//判断两个链表是否为空
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	int lenA = 0;
	int lenB = 0;
	struct ListNode* curA = headA, *curB = headB;
	//求A  B链表的长度
	while (curA)
	{
		curA = curA->next;
		lenA++;
	}
	while (cueB)
	{
		curB = curB->next;
		lenB++;
	}
	//判断两个链表是否相交
	//判断的是尾部是否一样，curA 与curB 已经改变值
	if (curA != curB)
	{
		return NULL;
	}

	struct ListNode* longList = headA, *shortList = headB;
	if (lenB > lenA)
	{
		longList = curB;
		shortList = curA;
	}

	//长的链表先走差距步
	struct gap = abs(lenA - lenB);
	while (gap--)
	{
		longList = longList->next;
	}

	//相等时就是交点
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}


//题目三
//给定一个链表，判断链表中是否有环。

//利用快慢指针
//思路：fast一次走两步，slow一次走一步，若是环，肯定会相遇
bool hasCycle(struct ListNode *head) {
	struct ListNode* slow = head, *fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)  //相等则就相遇
		{
			return true;
		}
	}
	return false;
}