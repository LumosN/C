int evalRPN(char ** tokens, int tokensSize){
	int i, result;
	int top = -1;
	int *stk = calloc(tokensSize, sizeof(int));

	if (!stk)
		return -1;
	for (i = 0; i < tokensSize; i++) {
		if (strcmp(tokens[i], "+") == 0)//����ǼӺţ���ջ������������
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
		else {//������Ƿ��ŵĻ�����ջ
			top++;
			stk[top] = atoi(tokens[i]);
		}
	}

	result = stk[0];//���Ϊջ�еĵ�һ��Ԫ��
	free(stk);

	return result;
}