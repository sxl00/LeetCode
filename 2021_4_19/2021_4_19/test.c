#define _CRT_SECURE_NO_WARNINGS 1
//[设计循环队列实现]

//循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

//你的实现应该支持如下操作：

//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。

//队列空的条件：front=tail
//队列满的条件：tail的下一个为front

//定义队列的结构体
typedef struct {
	int* a;
	int k;   //队列最多能存多少个数据
	int front;  //头
	int tail;   //尾（队尾数据下一个）
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));  //一个队列的别名
	cq->a = (int*)malloc(sizeof(int)*(k + 1));   //为数组开辟空间，要多开一个
	cq->front = 0;
	cq->tail = 0;
	cq->k = k;

	return cq;

}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	int tailNext = obj->tail + 1;
	if (tailNext == obj->k + 1)
	{
		tailNext = 0;
	}
	return tailNext == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		obj->a[obj->tail] = value;
		++obj->tail;

		if (obj->tail == obj->k + 1)   //到最后一个结点 
			obj->tail = 0;

		return true;
	}

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	else
	{
		++obj->front;
		if (obj->front == obj->k + 1)
		{
			obj->front = 0;
		}
		return true;
	}
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->a[obj->front];
	}

}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		int tailPrev = obj->tail - 1;
		if (tailPrev == -1)
			tailPrev = obj->k;
		return obj->a[tailPrev];
	}

}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->a);
	free(obj);
}

