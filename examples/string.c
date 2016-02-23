#include <stdio.h>
#include <string.h>

int main()
{
	char str1[64] = "Life is Beautiful ";
	char str2[32] = "World is a good place to live";
	printf("%s\n", strcat(str1, str2));
	
	strcpy(str1, str2);
	
	printf("%s\n", str1);
	
	return 0;
}

int main2()
{
	char string1[32];
	char string2[32];
	char op[2];
	scanf("%s", string1);
	getchar();
	scanf("%s", string2);
	int c = strcmp(string1, string2);
	if (c == 0) {
		strcpy(op, "=");
	} else if (c < 0) {
		strcpy(op, "<");
	} else {
		strcpy(op, ">");
	}
	printf("%s %s %s \n", string1, op, string2);
	return 0;
}
