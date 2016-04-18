#include <stdio.h>

int main(int argc, char *argv[])
{
	char *ptr1;
	char *ptr2;
	char a[]="Hello";
	char b[]="World";
	
	ptr1 = a;
	ptr2 = b;
	ptr1 = ptr1 + 2;
	ptr2 ++;
	
	// l, o, l
	printf("%c %c %c \n",*ptr1,*ptr2,*(ptr2+2) );
	return 0;
}
