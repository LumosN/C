typedef char STDateType;
typedef struct stack
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
bool isValid(char * s){
	stack st;
	stackInit(&st);
	bool ret;
	while (*s != '\0')
	{
		//��ǰ���� ��ջ
		if (*s == '[' || *s == '(' || *s == '{')
		{
			stackPush(&st, *s);
			s++;
		}
		else//��������ջ��Ԫ����Ƚ�
		{
			if (stackEmpty(&st)) //���ջ���ǿգ�˵�������ű�ǰ���Ŷ�
			{
				ret = false;
				break;
			}
			char top = stackTop(&st);//ȡջ��Ԫ��
			if (*s == ']' && top != '[')
			{
				ret = false;
				break;
			}
			if (*s == ')' && top != '(')
			{
				ret = false;
				break;
			}
			if (*s == '}' && top != '{')
			{
				ret = false;
				break;
			}
			stackPop(&st);//����
			s++;//������
		}
	}
	if (*s == '\0')//˵��ǰ���űȺ�������
	{
		ret = stackEmpty(&st);//�ж�ջ�ﻹ����ǰ���ţ���0��û�з�0
	}
	stackDestory(&st);
	return ret == 0 ? false : true;
}