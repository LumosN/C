bool isLongPressedName(char * name, char * typed){
	int i = 0, j = 0;
	while (j < strlen(typed))
	{
		if (i<strlen(name) && name[i] == typed[j])
		{
			i++;
			j++;
		}
		else if (j > 0 && typed[j] == typed[j - 1])
		{
			j++;
		}
		else return false;
	}
	return i == strlen(name);
}