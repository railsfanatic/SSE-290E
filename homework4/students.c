/*	HOMEWORK 4.3 & 4.4
	Filename: students.c
	Description: Allows user to enter up to NUM_STUDENTS
		of student data structs, then allows user
		to print info for students and
		find a student by last name.
	by Tom Grushka
	3/17/2016
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STUDENTS 100

struct STUDENT
{
	char firstName[32];
	char lastName[32];
	int completedCredits;
	struct tm enrollmentDate;
};

struct STUDENT students[100];
int numStudents = 0;

int saveStudents()
{
	int i;
	FILE *file;
	
	file = fopen("students.dat", "wb");
	if (!file)
	{
		printf("Unable to open file!\n");
		return 1;
	}
	
	printf("Saving %d students ...\t", numStudents);
	fwrite(&numStudents, sizeof(int), 1, file);
	for (i = 0; i < numStudents; i++)
	{
		fwrite(&students[i], sizeof(struct STUDENT), 1, file);
		printf("%d\t", i);
	}
	
	fclose(file);
	return 0;
}

int loadStudents()
{
	int i;
	FILE *file;
	
	file = fopen("students.dat", "rb");
	if (!file)
	{
		printf("Unable to open file!\n");
		return 1;
	}
	
	fread(&numStudents, sizeof(int), 1, file);
	printf("\nLoading %d students ...\t", numStudents);
	for (i = 0; i < numStudents; i++)
	{
		fread(&students[i], sizeof(struct STUDENT), 1, file);
		printf("%d\t", i);
	}
	
	fclose(file);
	return 0;
}

// http://stackoverflow.com/questions/352055/best-algorithm-to-strip-leading-and-trailing-spaces-in-c
void stripWhitespace(char *string) {
	/* First remove leading spaces */
	const char* firstNonSpace = string;
	while (*firstNonSpace != '\0' && isspace(*firstNonSpace))
		++firstNonSpace;
	
	size_t len = strlen(firstNonSpace)+1;         
	memmove(string, firstNonSpace, len);
	/* Now remove trailing spaces */
	char* endOfString = string + len;
	while(string < endOfString  && isspace(*endOfString))
		--endOfString;
	
	*endOfString = '\0';
}

/*	func:	inputString
	in:		prompt (const char*) - prompt to display
			size (size_t) - max size of input string
	out:	pointer to input string (char)
	desc:	prompts user, then uses fgets() to input a string;
			truncates and discards any input after size chars
*/
char *inputString(const char *prompt, size_t size)
{
	char *in = malloc(size);
	int i = 0;
	char c = 0;
	
	printf("%s", prompt);
	fgets(in, size, stdin);	// get a line
	
	for (i = 0; i < size; i++)	// look for newline (if not found, we've overrun)
		if (in[i] == '\n')
			c = !(in[i] = 0);	// using c as temp flag to skip getchar() if newline found
	
	// if we didn't find newline, flush overrun chars
	if (c == 0) while ((c = getchar()) != '\n' && c != 0);
	
	stripWhitespace(in);
	
	return in;
}

struct tm inputDate(const char* prompt)
{
	int m = 0;
	int d = 0;
	int y = 0;
	char tempDate[10];
	
	do
	{
		strcpy(tempDate, inputString(prompt, 10));
		sscanf(tempDate, "%d/%d/%d", &m, &d, &y);
		if (y < 100 && y >= 30) y += 1900;
		if (y < 30) y += 2000;
	} while ((m < 1 || m > 12) ||
			(d < 1 || d > 31) ||
			(y < 1900 || y > 2100));
	
	struct tm date = {
		.tm_mon = m - 1,
		.tm_mday = d,
		.tm_year = y - 1900
	};
	mktime(&date);
	
	return date;
}

int inputInteger(const char *prompt)
{
	return atoi(inputString(prompt, 10));
}

int confirm(const char *prompt)
{
	char *conf = inputString(prompt, 100);
	if (strcmp(conf, "y") == 0 || strcmp(conf, "Y") == 0) return 1;
	else return 0;
}

void addStudents()
{
	char firstName[32];
	char lastName[32];
	int completedCredits;
	struct tm enrollmentDate;
	struct STUDENT *s;
	
	printf("Add Students\n============\n\n"
		"Start entering students. Leave first name blank to stop.\n\n");
	
	do {
		do {
			printf("Student #%d\n", numStudents + 1);
			
			strcpy(firstName, inputString("First name: ", 32));
			if (strcmp(firstName, "") == 0) return;
	
			strcpy(lastName, inputString("Last name: ", 32));
			if (strcmp(lastName, "") == 0) return;
	
			completedCredits = inputInteger("Completed credits: ");
	
			enrollmentDate = inputDate("Enrollment date (mm/dd/yyyy): ");
			
			printf("\nFirst name: %s\n"
				"Last name: %s\n"
				"Completed credits: %d\n"
				"Enrollment date: %s\n",
					firstName,
					lastName,
					completedCredits,
					asctime(&enrollmentDate));
		} while (!confirm("Info correct (y/n) ?"));
		
		s = &students[numStudents];
		
		strcpy(s->firstName, firstName);
		strcpy(s->lastName, lastName);
		s->completedCredits = completedCredits;
		s->enrollmentDate = enrollmentDate;
		
		numStudents ++;
		
	} while (confirm("Add another student (y/n) ?"));
}

char *formatDate(struct tm d)
{
	char *s = malloc(10 * sizeof(char));
	strftime(s, 10, "%m/%d/%Y", &d);
	return s;
}

void printStudent(struct STUDENT *s)
{
	printf("%s, %s\n", s->lastName, s->firstName);
	printf("Date enrolled: %s\n", formatDate(s->enrollmentDate));
	printf("Completed credits: %d\n", s->completedCredits);
}

char *formatName(char *fn, char *ln, int lnf)
{
	char *s = malloc(66 * sizeof(char));
	if (lnf)
		sprintf(s, "%s, %s", ln, fn);
	else
		sprintf(s, "%s %s", fn, ln);
	return s;
}

void editStudent(int i)
{
	if (i < 1 || i > numStudents) return;
	i --;
	
	printf("Editing student:\n");
	printStudent(&students[i]);
}

void listStudents()
{
	struct STUDENT *s;
	int i;
	
	printf("ALL STUDENTS\n\n");
	
	printf(	"  #  Student Name\t\t\tEnrolled    Credits\n"
			"===  ============\t\t\t==========  =======\n");
	for (i = 0; i < numStudents; i++)
	{
		s = &students[i];
		printf("%3d  "     // ###
			"%-34.34s "    // last, first
			"%10s  "       // mm/dd/yyyy
			"%7d\n",       // ###
			i+1,
			formatName(s->firstName, s->lastName, 1),
			formatDate(s->enrollmentDate),
			s->completedCredits);
	}
	printf("\n");
	
	i = inputInteger("Enter # to edit, Enter to return to menu. ");
	if (i < 1 || i > numStudents) return;
	editStudent(i);
}

int main()
{
	int choice = 0;
	
	do {
		printf("\n\nWelcome to STUDENTS!\n===================\n\n"
			"There are currently %d students in memory.\n\n"
			"1.  Add New Student(s)\n\n"
			"2.  Find Students\n\n"
			"3.  List All Students\n\n"
			"4.  Load Students File (./students.dat)\n\n"
			"5.  Save Students File (./students.dat)\n\n"
			"6.  Quit\n\n", numStudents);
		
		choice = inputInteger("Choice: ");
		printf("\n");
		
		switch (choice)
		{
			case 1: // add
				addStudents();
				break;
			case 2: // find
				//findStudent();
				break;
			case 3: // list
				listStudents();
				break;
			case 4: // load
				if (numStudents == 0 || confirm("Overwrite memory with students from file (y/n) ? "))
					loadStudents();
				break;
			case 5: // save
				if (confirm("Overwrite the file (y/n) ? "))
					saveStudents();
				break;
			default: // quit
				if (confirm("Are you sure you want to quit (y/n) ? "))
				{
					printf("\nGoodbye!\n");
					exit(0);
				}
				break;
		}
	} while (1);
	
	return 0;
}

