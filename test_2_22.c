char * addBinary(char * a, char * b){
	int alen = strlen(a);
	int blen = strlen(b);
	int len = alen > blen ? alen : blen;
	char* p = (char*)malloc(sizeof(char)* (len + 2));

	int carry = 0, i = 0, k = 0;//carry 进位的标记
	while (i < alen && i < blen){
		if (a[alen - 1 - i] == '1' && b[blen - 1 - i] == '1'){ //
			p[k++] = carry + '0';
			carry = 1;
		}
		else if ((carry == 1 && a[alen - 1 - i] == '1') || (carry == 1 && b[blen - 1 - i] == '1')){
			p[k++] = '0';//有进位的情况并且有一个位是1，这样也要进位
			carry = 1; //要进位
		}
		else{
			p[k++] = ((a[alen - 1 - i] - '0') + (b[blen - 1 - i] - '0') + carry) + '0';
			carry = 0;
		}
		i++;
	}
	//处理长出来的部分
	while (i < alen){
		if (a[alen - 1 - i] == '1' && carry == 1){
			p[k++] = '0';
			carry = 1;
		}
		else{
			p[k++] = (a[alen - 1 - i] - '0' + carry) + '0';
			carry = 0;
		}
		i++;
	}
	while (i < blen){
		if (b[blen - 1 - i] == '1' && carry == 1){
			p[k++] = '0';
			carry = 1;
		}
		else{
			p[k++] = (b[blen - 1 - i] - '0' + carry) + '0';
			carry = 0;
		}
		i++;
	}

	if (carry == 1){
		p[k++] = '1';
	}
	//逆序
	for (int j = 0; j < k / 2; j++){
		char t = p[j];
		p[j] = p[k - j - 1];
		p[k - j - 1] = t;
	}

	p[k] = '\0';
	return p;
}