typedef int STDateType;
typedef struct stack//ջ������ʵ�ָ���һ��
{
	STDateType* a;
	int size;
	int capacity;
}stack;
void stackInit(stack* pst)
{
	assert(pst);
	pst->a = (STDateType*)malloc(sizeof(STDateType)* 4);
	pst->size = 0;
	pst->capacity = 4;
}
void stackDestory(stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->size = pst->capacity = 0;
}
//��ջ
void stackPush(stack* pst, STDateType x)
{
	assert(pst);
	if (pst->size == pst->capacity)
	{
		pst->capacity *= 2;
		STDateType* tmp = (STDateType*)realloc(pst->a, sizeof(STDateType)*pst->capacity);
		pst->a = tmp;
	}
	pst->a[pst->size] = x;
	pst->size++;
}
//��ջ
void stackPop(stack* pst)
{
	assert(pst);
	assert(pst->size > 0);
	pst->size--;
}
int stackEmpty(stack* pst)//����1�ǿգ�����0�Ƿǿ�
{
	assert(pst);
	return pst->size == 0 ? 1 : 0;
}
//��ȡջ��������
STDateType stackTop(stack* pst)
{
	assert(pst);
	assert(pst->size > 0);
	return pst->a[pst->size - 1];
}
typedef struct {
	stack pushST;
	stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&q->pushST);
	stackInit(&q->popST);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);//ȡ��ͷ
	stackPop(&obj->popST);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!stackEmpty(&obj->popST))
	{
		return stackTop(&obj->popST);
	}
	else
	{
		while (!stackEmpty(&obj->pushST))
		{
			stackPush(&obj->popST, stackTop(&obj->pushST));
			stackPop(&obj->pushST);
		}
		return stackTop(&obj->popST);
	}
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (stackEmpty(&obj->pushST) && stackEmpty(&obj->popST))
	{
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) {
	stackDestory(&obj->pushST);
	stackDestory(&obj->popST);
	free(obj);
	obj = NULL;
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/