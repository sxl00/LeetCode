#define _CRT_SECURE_NO_WARNINGS 1
//203.移除链表元素
//给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;

	while (cur)      //只要cur!=NULL就循环
	{
		struct ListNode* next = cur->next;  //next 是cur的下一个结点
		if (cur->val == val)
		{
			if (prev == head)  //cur是头,值在第一个
			{
				free(cur);
				head = next;
				cur = next;
			}
			else
			{
				prev->next = next;    //cur前一个结点的指针指向cur的下一个结点
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


//206.反转链表
//反转一个单链表。
//l.利用3个指针翻转
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
	while (n2)  //直到n2为空结束循坏
	{
		//翻转
		n2->next = n1;

		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//2.头插法，不创建新结点
//整体思路：取原链表中的结点头插到新结点，要先保存一个结点的下一个地址，不然取结点后找不到后面的结点
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


//876.链表的中间结点
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。

//如果有两个中间结点，则返回第二个中间结点。


//思路：快慢指针，快指针一次走两步，慢指针一次走一步，遍历一次
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* fast = head, *slow = head;
	while (fast && fast->next)  //条件是循环的条件
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;   //slow是中间结点
}
