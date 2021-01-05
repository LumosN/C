//只有弹出数据的时候要借助两个队列，取栈顶元素的时候可以直接利用队尾指针即可
typedef char QDataType;
typedef struct queueNode
{
	struct queueNode* next;
	QDataType data;
}queueNode;
typedef struct queue
{
	queueNode* head;
	queueNode* tail;
}queue;
void queueInit(queue* pq)
{
	assert(pq);
	(pq)->head = NULL;
	(pq)->tail = NULL;
}
void queueDestory(queue* pq)
{
	assert(pq);
	queueNode* cur = pq->head;
	while (cur)
	{
		queueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void queuePush(queue* pq, QDataType x)
{
	assert(pq);
	queueNode* newnode = (queueNode*)malloc(sizeof(queueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void queuePop(queue* pq)
{
	assert(pq);
	assert(pq->head);
	queueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}
QDataType queueFront(queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType queueBack(queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
int queueEmpty(queue* pq)//返回1是空，0是非空
{
	if (pq->head == NULL)
	{
		return 1;
	}
	else return 0;
}
int queueSize(queue* pq)
{
	assert(pq);
	int size = 0;
	queueNode* cur = pq->head;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
typedef struct {
	queue q1;
	queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&obj->q1);
	queueInit(&obj->q2);
	return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!queueEmpty(&obj->q1))//将数据入到不为空的队列里
	{
		queuePush(&obj->q1, x);
	}
	else
	{
		queuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	queue* empty = &obj->q1;
	queue* nonEmpty = &obj->q2;
	if (queueEmpty(&obj->q2))//如果q2为空
	{
		empty = &obj->q2;
		nonEmpty = &obj->q1;
	}
	while (queueSize(nonEmpty) > 1)//对非空的队列操作
	{
		queuePush(empty, queueFront(nonEmpty));
		queuePop(nonEmpty);
	}
	int top = queueFront(nonEmpty);
	queuePop(nonEmpty);//把最后一个数据弹掉
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!queueEmpty(&obj->q1))
	{
		return queueBack(&obj->q1);
	}
	else//如果两者都为空，该题不会调用该接口
	{
		return queueBack(&obj->q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (queueEmpty(&obj->q1) && queueEmpty(&obj->q2))
	{
		return true;
	}
	return false;
}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->q1);
	queueDestory(&obj->q2);
	free(obj);
	obj = NULL;
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/