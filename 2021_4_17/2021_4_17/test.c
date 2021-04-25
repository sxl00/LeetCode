#define _CRT_SECURE_NO_WARNINGS 1
//括号匹配问题
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

//有效字符串需满足：

//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。


typedef char  STDataType;
struct Stack
{
	STDataType* a;  //数组
	int top;       //栈顶
	int capacity;  //容量，方便增容
};

typedef struct Stack Stack;

//只改变形参，改变不了实参
void StackInit(Stack* pst);
void StackDestroy(Stack*  pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);

//空返回1,非空返回0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);


//初始化栈
void StackInit(Stack* pst)
{
	assert(pst);

	//不方便增容
	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//销毁栈
void StackDestroy(Stack*  pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  //结束整个程序
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	//入数据
	pst->a[pst->top] = x;
	pst->top++;
}


//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

bool isValid(char * s){
	Stack st;
	StackInit(&st);
	while (*s)
	{
		//左括号入栈，右括号找最近的左括号匹配
		if (*s == '[' || *s == '(' || *s == '{')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			//为空，说明没有前括号
			if (StackEmpty(&st))
				return false;
			char top = StackTop(&st);

			if ((top == '[' && *s != ']') || (top == '(' && *s != ')') || (top == '{' && *s != '}'))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				//匹配
				StackPop(&st);
				++s;
			}
		}
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);

	return ret;
}


//2.用队列实现栈
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，
//并支持普通队列的全部四种操作（push、top、pop 和 empty）。

//实现 MyStack 类：

//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false


//两个队列
//入数据，往不为空的那个队列入
//保持另一个队列为空
//出数据，前size-1个倒空队列


typedef int QDataType;

//定义结点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

//定义队列
typedef struct Queue  //若不用typedef,则后面函数定义变量必须使用struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


//初始化
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//进队列
void QueuePush(Queue* pq, QDataType x);

//出队列
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);


//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;

}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//pq->tail->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{

		pq->tail->next = newnode;  //tail的next指向newnode
		pq->tail = newnode;  //把新的地址重新赋给tail的next
	}
}

//队头出数据
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//只有一个结点，直接使结点指向NULL
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}

int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}




typedef struct {  //栈中定义两个所需队列q1   q2
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	//malloc只有手动释放才会没有，若不这样写，出了函数，pst会销毁，成为野指针
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//两个队列的初始化
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
//入数据，哪一个不为空就进入哪一个队列
//保持另一个队列为空
//传的是q1   q2结构体，要传地址则obj要加&
void myStackPush(MyStack* obj, int x) {  //将MyStack指针数据传给obj
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}

}

/** Removes the element on top of the stack and returns that element. */
//删除数据，把前size-1个倒空队列，删除最后一个数据
//最后返回栈顶数据
int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1;  //指向空队列的指针，指向q1
	Queue* pNoneEmpty = &obj->q2;  //指向非空队列的指针，指向q2

	//假设q1不为空，可确定哪一个队列为空
	if (!QueueEmpty(&obj->q1))
	{
		pEmpty = &obj->q2;
		pNoneEmpty = &obj->q1;
	}

	//把非空队列里面数据取出
	while (QueueSize(pNoneEmpty) > 1)
	{
		QueuePush(pEmpty, QueueFront(pNoneEmpty));  //非空队列里面从队头依次取出数据放入空队列
		QueuePop(pNoneEmpty);  //把非空队列里面剩下的最后一个数据取出队列
	}

	int front = QueueFront(pNoneEmpty);  //返回要删除的值
	QueuePop(pNoneEmpty);
	return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	//判断两队列谁为空，哪一个队列不为空，数据就进入哪一个队列
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

/** Returns whether the stack is empty. */
//判断队列是否为空
bool myStackEmpty(MyStack* obj) {
	//两个队列均为空才为空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//两队列是链表，都要释放和手动扩增的一个Mystack也需要释放
void myStackFree(MyStack* obj) {
	//两队列的释放可以直接调用队列的销毁函数
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

//3.用栈实现队列
//请你仅使用两个栈实现先入先出队列。
//队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

//实现 MyQueue 类：

//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false

//思路：

//（1）把PushST栈中的size-1个元素倒入PopST栈中，将最后一个1出栈；
//（2）再把PopST栈中的元素依次出栈；
//（3）若还要进栈，则进入PushST栈中，再利用（1）、（2）方法进行出栈顺序。

typedef int STDataType;
struct Stack
{
	STDataType* a;  //数组
	int top;       //栈顶
	int capacity;  //容量，方便增容
};

typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack*  pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);

//空返回1,非空返回0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);

//初始化栈
void StackInit(Stack* pst)
{
	assert(pst);

	//不方便增容
	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//销毁栈
void StackDestroy(Stack*  pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  //结束整个程序
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	//入数据
	pst->a[pst->top] = x;
	pst->top++;
}


//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

//在队列中定义两个所需的栈
typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//将数据进入栈
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));  //将栈中有元素的栈中元素倒入到另一个栈中
			StackPop(&obj->pushST);  //把栈中有元素的栈的最后一个元素出栈
		}
	}
	int top = StackTop(&obj->popST);  //依次从PopST栈中出数据
	StackPop(&obj->popST);  //返回出栈数据值
	return top;
}

/** Get the front element. */
//获取队头数据
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));  //将栈中有元素的栈中元素倒入到另一个栈中
			StackPop(&obj->pushST);  //把栈中有元素的栈的最后一个元素出栈
		}
	}
	return StackTop(&obj->popST);  //获取栈数据元素
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	//只要有一个不为空都不算为空
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}





