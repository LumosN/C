int evalRPN(char ** tokens, int tokensSize){
	int i, result;
	int top = -1;
	int *stk = calloc(tokensSize, sizeof(int));

	if (!stk)
		return -1;
	for (i = 0; i < tokensSize; i++) {
		if (strcmp(tokens[i], "+") == 0)//如果是加号，出栈，两个做运算
		{
			top -= 1;
			stk[top] = stk[top] + stk[top + 1];
		}
		else if (strcmp(tokens[i], "-") == 0) {
			top -= 1;
			stk[top] = stk[top] - stk[top + 1];
		}
		else if (strcmp(tokens[i], "*") == 0) {
			top -= 1;
			stk[top] = stk[top] * stk[top + 1];
		}
		else if (strcmp(tokens[i], "/") == 0) {
			top -= 1;
			stk[top] = stk[top] / stk[top + 1];
		}
		else {//如果不是符号的话，进栈
			top++;
			stk[top] = atoi(tokens[i]);
		}
	}

	result = stk[0];//结果为栈中的第一个元素
	free(stk);

	return result;
}