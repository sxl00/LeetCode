#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀһ��
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨��
//�ж����Ƿ�Ϊ���Ľṹ��

//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ��
//��֤������С�ڵ���900��

//����������1->2->2->1
//���أ�true

//˼·�������м��㣬ʹ��벿�����ã����Ƚ�

//�����м���
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

//���ú�벿�֣�Ҳ�Ƿ�ת����
//��벿������
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
				//cur->next�ı���ָ��Ķ���ָ��newHead,newHead��һ��ָ�����NULL
	// 	        cur->next = newHead;
	// 	    	newHead = cur;

	// 		    cur = cur->next;
	// 	    }
	//      	return newHead;
}
//�Ƚ�
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


//��Ŀ����
//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//1.�ж��Ƿ��ཻ
//2.�ཻ�󽻵�
//�ý��ĵ�ַ��ȣ�������ֵ��ȣ��ж�βָ���Ƿ���ͬ��
//�������������ĳ��ȣ��ó����������߲�ಽ
//��ͬʱ�ߣ���һ����ͬ�Ľ�㣬���ǽ���

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	//�ж����������Ƿ�Ϊ��
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	int lenA = 0;
	int lenB = 0;
	struct ListNode* curA = headA, *curB = headB;
	//��A  B����ĳ���
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
	//�ж����������Ƿ��ཻ
	//�жϵ���β���Ƿ�һ����curA ��curB �Ѿ��ı�ֵ
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

	//�����������߲�ಽ
	struct gap = abs(lenA - lenB);
	while (gap--)
	{
		longList = longList->next;
	}

	//���ʱ���ǽ���
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}


//��Ŀ��
//����һ�������ж��������Ƿ��л���

//���ÿ���ָ��
//˼·��fastһ����������slowһ����һ�������ǻ����϶�������
bool hasCycle(struct ListNode *head) {
	struct ListNode* slow = head, *fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)  //����������
		{
			return true;
		}
	}
	return false;
}