#define _CRT_SECURE_NO_WARNINGS 1
//[���ѭ������ʵ��]

//ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

//���ʵ��Ӧ��֧�����²�����

//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//isFull() : ���ѭ�������Ƿ�������

//���пյ�������front=tail
//��������������tail����һ��Ϊfront

//������еĽṹ��
typedef struct {
	int* a;
	int k;   //��������ܴ���ٸ�����
	int front;  //ͷ
	int tail;   //β����β������һ����
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));  //һ�����еı���
	cq->a = (int*)malloc(sizeof(int)*(k + 1));   //Ϊ���鿪�ٿռ䣬Ҫ�࿪һ��
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

		if (obj->tail == obj->k + 1)   //�����һ����� 
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

