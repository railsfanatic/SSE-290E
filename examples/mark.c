/*	mark.c:
	Display mark range for entered letter grade.
	by Tom Grushka
	February 3, 2016	*/

#include <stdio.h>
#include <string.h>

// this is a test

int main(int argc, const char *argv[])
{
	char *grade;
	
	//if (argc == 2) {
		grade = (char *)argv[1];
	//} else {
	//	printf("Enter a letter grade: ");
	//	fgets(grade, 1, stdin);
	//}
	
	printf("Grade: %c \n", *grade);
	
	switch (*grade) {
		case 'A':
		case 'a':
			printf("The mark is 90 to 100.\n");
			break;
		case 'B':
		case 'b':
			printf("The mark is 80 to under 90.\n");
			break;
		case 'C':
		case 'c':
			printf("The mark is 70 to under 80.\n");
			break;
		case 'D':
		case 'd':
			printf("The mark is 60 to under 70.\n");
			break;
		case 'F':
		case 'f':
			printf("The mark is below 60.\n");
			break;
		default:
			printf("Invalid grade entered.\n");
	}
}
