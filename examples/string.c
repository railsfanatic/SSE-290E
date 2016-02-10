#include <stdio.h>
#include <string.h>

int main()
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
