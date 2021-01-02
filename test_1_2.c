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
//入栈
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
//出栈
void stackPop(stack* pst)
{
	assert(pst);
	assert(pst->size > 0);
	pst->size--;
}
int stackEmpty(stack* pst)//返回1是空，返回0是非空
{
	assert(pst);
	return pst->size == 0 ? 1 : 0;
}
//获取栈顶的数据
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
		//是前括号 入栈
		if (*s == '[' || *s == '(' || *s == '{')
		{
			stackPush(&st, *s);
			s++;
		}
		else//后括号与栈顶元素相比较
		{
			if (stackEmpty(&st)) //如果栈里是空，说明后括号比前括号多
			{
				ret = false;
				break;
			}
			char top = stackTop(&st);//取栈顶元素
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
			stackPop(&st);//弹出
			s++;//继续比
		}
	}
	if (*s == '\0')//说明前括号比后括号少
	{
		ret = stackEmpty(&st);//判断栈里还有无前括号，有0，没有非0
	}
	stackDestory(&st);
	return ret == 0 ? false : true;
}