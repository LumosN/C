bool canConstruct(char * ransomNote, char * magazine){
	int count[26] = { 0 };
	int lenR = strlen(ransomNote);
	int lenM = strlen(magazine);
	for (int i = 0; i < lenM; i++)
	{
		count[magazine[i] - 'a']++;
	}
	for (int i = 0; i < lenR; i++)
	{
		if (count[ransomNote[i] - 'a'] == 0)
		{
			return false;
		}
		else count[ransomNote[i] - 'a']--;
	}
	return true;
}
