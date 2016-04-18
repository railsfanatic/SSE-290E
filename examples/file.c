#include <stdio.h>

int main()
{
	FILE *fp1, *fp2;
	char c;
	
	printf("Opening Inputfile.txt & Outputfile.txt...\n");
	
	fp1 = fopen("Inputfile.txt", "r");
	fp2 = fopen("Outputfile.txt", "w");
	c = fgetc(fp1);
	
	while (!feof(fp1))
	{
		fputc(c, fp2);
		c = fgetc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
	
	fp2 = fopen("Outputfile.txt", "r");
	c = fgetc(fp2);
	while(!feof(fp2))
	{
		printf("%c", c);
		c = getc(fp2);
	}
	
	return 0;
}