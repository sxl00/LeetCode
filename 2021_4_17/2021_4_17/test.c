#define _CRT_SECURE_NO_WARNINGS 1
//����ƥ������
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

//��Ч�ַ��������㣺

//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�


typedef char  STDataType;
struct Stack
{
	STDataType* a;  //����
	int top;       //ջ��
	int capacity;  //��������������
};

typedef struct Stack Stack;

//ֻ�ı��βΣ��ı䲻��ʵ��
void StackInit(Stack* pst);
void StackDestroy(Stack*  pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);

//�շ���1,�ǿշ���0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);


//��ʼ��ջ
void StackInit(Stack* pst)
{
	assert(pst);

	//����������
	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//����ջ
void StackDestroy(Stack*  pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  //������������
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	//������
	pst->a[pst->top] = x;
	pst->top++;
}


//��ջ
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
		//��������ջ���������������������ƥ��
		if (*s == '[' || *s == '(' || *s == '{')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			//Ϊ�գ�˵��û��ǰ����
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
				//ƥ��
				StackPop(&st);
				++s;
			}
		}
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);

	return ret;
}


//2.�ö���ʵ��ջ
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ��
//��֧����ͨ���е�ȫ�����ֲ�����push��top��pop �� empty����

//ʵ�� MyStack �ࣺ

//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false


//��������
//�����ݣ�����Ϊ�յ��Ǹ�������
//������һ������Ϊ��
//�����ݣ�ǰsize-1�����ն���


typedef int QDataType;

//������
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

//�������
typedef struct Queue  //������typedef,����溯�������������ʹ��struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


//��ʼ��
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//������
void QueuePush(Queue* pq, QDataType x);

//������
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);


//��ʼ��
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

		pq->tail->next = newnode;  //tail��nextָ��newnode
		pq->tail = newnode;  //���µĵ�ַ���¸���tail��next
	}
}

//��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//ֻ��һ����㣬ֱ��ʹ���ָ��NULL
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

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//ȡ��β����
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




typedef struct {  //ջ�ж��������������q1   q2
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	//mallocֻ���ֶ��ͷŲŻ�û�У���������д�����˺�����pst�����٣���ΪҰָ��
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//�������еĳ�ʼ��
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
//�����ݣ���һ����Ϊ�վͽ�����һ������
//������һ������Ϊ��
//������q1   q2�ṹ�壬Ҫ����ַ��objҪ��&
void myStackPush(MyStack* obj, int x) {  //��MyStackָ�����ݴ���obj
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
//ɾ�����ݣ���ǰsize-1�����ն��У�ɾ�����һ������
//��󷵻�ջ������
int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1;  //ָ��ն��е�ָ�룬ָ��q1
	Queue* pNoneEmpty = &obj->q2;  //ָ��ǿն��е�ָ�룬ָ��q2

	//����q1��Ϊ�գ���ȷ����һ������Ϊ��
	if (!QueueEmpty(&obj->q1))
	{
		pEmpty = &obj->q2;
		pNoneEmpty = &obj->q1;
	}

	//�ѷǿն�����������ȡ��
	while (QueueSize(pNoneEmpty) > 1)
	{
		QueuePush(pEmpty, QueueFront(pNoneEmpty));  //�ǿն�������Ӷ�ͷ����ȡ�����ݷ���ն���
		QueuePop(pNoneEmpty);  //�ѷǿն�������ʣ�µ����һ������ȡ������
	}

	int front = QueueFront(pNoneEmpty);  //����Ҫɾ����ֵ
	QueuePop(pNoneEmpty);
	return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	//�ж�������˭Ϊ�գ���һ�����в�Ϊ�գ����ݾͽ�����һ������
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
//�ж϶����Ƿ�Ϊ��
bool myStackEmpty(MyStack* obj) {
	//�������о�Ϊ�ղ�Ϊ��
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//��������������Ҫ�ͷź��ֶ�������һ��MystackҲ��Ҫ�ͷ�
void myStackFree(MyStack* obj) {
	//�����е��ͷſ���ֱ�ӵ��ö��е����ٺ���
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

//3.��ջʵ�ֶ���
//�����ʹ������ջʵ�������ȳ����С�
//����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����

//ʵ�� MyQueue �ࣺ

//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false

//˼·��

//��1����PushSTջ�е�size-1��Ԫ�ص���PopSTջ�У������һ��1��ջ��
//��2���ٰ�PopSTջ�е�Ԫ�����γ�ջ��
//��3������Ҫ��ջ�������PushSTջ�У������ã�1������2���������г�ջ˳��

typedef int STDataType;
struct Stack
{
	STDataType* a;  //����
	int top;       //ջ��
	int capacity;  //��������������
};

typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack*  pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

STDataType StackTop(Stack* pst);

//�շ���1,�ǿշ���0
bool StackEmpty(Stack* pst);

int StackSize(Stack* pst);

//��ʼ��ջ
void StackInit(Stack* pst)
{
	assert(pst);

	//����������
	/*pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;*/

	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//����ջ
void StackDestroy(Stack*  pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  //������������
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	//������
	pst->a[pst->top] = x;
	pst->top++;
}


//��ջ
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

//�ڶ����ж������������ջ
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
	//�����ݽ���ջ
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));  //��ջ����Ԫ�ص�ջ��Ԫ�ص��뵽��һ��ջ��
			StackPop(&obj->pushST);  //��ջ����Ԫ�ص�ջ�����һ��Ԫ�س�ջ
		}
	}
	int top = StackTop(&obj->popST);  //���δ�PopSTջ�г�����
	StackPop(&obj->popST);  //���س�ջ����ֵ
	return top;
}

/** Get the front element. */
//��ȡ��ͷ����
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));  //��ջ����Ԫ�ص�ջ��Ԫ�ص��뵽��һ��ջ��
			StackPop(&obj->pushST);  //��ջ����Ԫ�ص�ջ�����һ��Ԫ�س�ջ
		}
	}
	return StackTop(&obj->popST);  //��ȡջ����Ԫ��
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	//ֻҪ��һ����Ϊ�ն�����Ϊ��
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}





