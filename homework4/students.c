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
	time_t enrollmentDate;
};

struct STUDENT students[MAX_STUDENTS];
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
	
	printf("Saving %d students ...\n", numStudents);
	fwrite(&numStudents, sizeof(int), 1, file);
	for (i = 0; i < numStudents; i++)
		fwrite(&students[i], sizeof(struct STUDENT), 1, file);
	
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
	printf("\nLoading %d students ...\n", numStudents);
	for (i = 0; i < numStudents; i++)
		fread(&students[i], sizeof(struct STUDENT), 1, file);
	
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
				INCLUDING null terminator
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

time_t inputDate(const char *prompt)
{
	int m = 0;
	int d = 0;
	int y = 0;
	char tempDate[10];
	struct tm date = {0};
	
	do
	{
		strcpy(tempDate, inputString(prompt, 10));
		if (strcmp(tempDate, "") == 0) return mktime(&date);
		
		sscanf(tempDate, "%d/%d/%d", &m, &d, &y);
		if (y < 100 && y >= 30) y += 1900;
		if (y < 30) y += 2000;
	} while ((m < 1 || m > 12) ||
			(d < 1 || d > 31) ||
			(y < 1900 || y > 2100));
	
	date.tm_mon = m - 1;
	date.tm_mday = d;
	date.tm_year = y - 1900;
	
	return mktime(&date);
}

int inputInteger(const char *prompt)
{
	return atoi(inputString(prompt, 10));
}

int confirm(const char *prompt)
{
	char *conf = inputString(prompt, 2);
	if (strcmp(conf, "y") == 0 || strcmp(conf, "Y") == 0) return 1;
	else return 0;
}

void addStudents()
{
	char firstName[32];
	char lastName[32];
	int completedCredits;
	time_t enrollmentDate;
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
					ctime(&enrollmentDate));
		} while (!confirm("Info correct (y/n) ?"));
		
		s = &students[numStudents];
		
		strcpy(s->firstName, firstName);
		strcpy(s->lastName, lastName);
		s->completedCredits = completedCredits;
		s->enrollmentDate = enrollmentDate;
		
		numStudents ++;
		
	} while (confirm("Add another student (y/n) ?"));
}

char *formatDate(time_t d)
{
	char *s = malloc(10 * sizeof(char));
	strftime(s, 10, "%m/%d/%Y", localtime(&d));
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

void editStudent(struct STUDENT *s)
{
	char firstName[32];
	char lastName[32];
	int completedCredits;
	time_t enrollmentDate = 0;
	time_t noDate = 0;
	
	do {
		printf("\nEditing Student #%d\n", numStudents + 1);
		
		printf("First name: [%s] ", s->firstName);
		strcpy(firstName, inputString("", 32));
		if (strcmp(firstName, "") == 0) strcpy(firstName, s->firstName);
		
		printf("Last name: [%s] ", s->lastName);
		strcpy(lastName, inputString("", 32));
		if (strcmp(lastName, "") == 0) strcpy(lastName, s->lastName);
		
		printf("Completed credits: [%d] ", s->completedCredits);
		completedCredits = inputInteger("");
		if (completedCredits == 0) completedCredits = s->completedCredits;
		
		printf("Enrollment date (mm/dd/yyyy): [%s] ", formatDate(s->enrollmentDate));
		enrollmentDate = inputDate("");
		if (difftime(enrollmentDate, noDate) == 0) enrollmentDate = s->enrollmentDate;
		
		printf("\nFirst name: %s\n"
			"Last name: %s\n"
			"Completed credits: %d\n"
			"Enrollment date: %s\n",
				firstName,
				lastName,
				completedCredits,
				ctime(&enrollmentDate));
	} while (!confirm("\nInfo correct (y/n) ?"));
	
	strcpy(s->firstName, firstName);
	strcpy(s->lastName, lastName);
	s->completedCredits = completedCredits;
	s->enrollmentDate = enrollmentDate;
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
	editStudent(&students[i-1]);
}

void sortStudents()
{
	char sortField;
	int i = 0;
	int sorted = 0;
	int swap = 0;
	time_t t1;
	time_t t2;
	struct STUDENT tempStudent;
	
	if (numStudents < 2) return;
	
	printf("Sort by:\t"
		"L) Last Name\n\t\t"
		"F) First Name\n\t\t"
		"E) Enrollment Date\n\t\t"
		"C) Completed Credits ? ");
	
	sortField = toupper(inputString("", 2)[0]);
	
	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < numStudents - 1; i++)
		{
			swap = 0;
			switch (sortField)
			{
				case 'F': // first name
					swap = ((strcmp(students[i+1].firstName, students[i].firstName) < 0)
						|| (strcmp(students[i+1].firstName, students[i].firstName) == 0
						&& strcmp(students[i+1].lastName, students[i].lastName) < 0));
					break;
				case 'E': // enrollment date
					t1 = students[i].enrollmentDate;
					t2 = students[i+1].enrollmentDate;
					swap = (difftime(t1, t2) > 0);
					break;
				case 'C': // completed credits
					swap = (students[i].completedCredits > students[i+1].completedCredits);
					break;
				case 'L': // last name
				default:
					swap = ((strcmp(students[i+1].lastName, students[i].lastName) < 0)
						|| (strcmp(students[i+1].lastName, students[i].lastName) == 0
						&& strcmp(students[i+1].firstName, students[i].firstName) < 0));
					break;
			}
			if (swap)
			{
				tempStudent = students[i];
				students[i] = students[i+1];
				students[i+1] = tempStudent;
				sorted = 0;
			}
		}
	}
	listStudents();
}

char *downcase(char *s)
{
	char *d = (char *)malloc(strlen(s) * sizeof(char));
	d = strdup(s);
	char *p = d;
	for ( ; *d; ++d) *d = tolower(*d);
	return p;
}

void findStudent()
{
	int i = 0;
	char *findLastName;
	char *lastName;
	int found[MAX_STUDENTS];
	int numFound = 0;
	
	printf("FIND STUDENT BY LAST NAME\n\n");
	
	do {
		numFound = 0;
		
		findLastName = downcase(inputString("Last name? ", 32));
		printf("\n\nSearching ... ");
		for (i = 0; i < numStudents; i++)
		{
			lastName = downcase(students[i].lastName);
			if (strstr(lastName, findLastName) != NULL)
			{
				found[numFound] = i;
				numFound ++;
			}
		}
		if (numFound == 0) printf("No matches found.\n");
		else
		{
			printf("Found %d students:\n\n", numFound);
			for (i = 0; i < numFound; i++)
			{
				printStudent(&students[found[i]]);
				printf("\n");
			}
		}
		
	} while (confirm("Find another (y/n) ? "));
}

void clearStudents()
{
	int i = 0;
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		memset(&students[i], 0, sizeof(struct STUDENT));
	}
	numStudents = 0;
}

int main()
{
	int choice = 0;
	
	do {
		printf("\n\nWelcome to STUDENTS!\n===================\n\n"
			"There are currently %d students in memory.\n\n"
			"1.  Add New Student(s)\n"
			"2.  Find Student by Last Name\n"
			"3.  List All Students\n"
			"4.  Sort Database\n"
			"5.  Load Students File (./students.dat)\n"
			"6.  Save Students File (./students.dat)\n"
			"7.  Clear Memory (New Database)\n"
			"8.  Quit\n\n", numStudents);
		
		choice = inputInteger("Choice: ");
		printf("\n");
		
		switch (choice)
		{
			case 1: // add
				addStudents();
				break;
			case 2: // find
				findStudent();
				break;
			case 3: // list
				listStudents();
				break;
			case 4: // sort
				sortStudents();
				break;
			case 5: // load
				if (numStudents == 0 || confirm("Overwrite memory with students from file (y/n) ? "))
					loadStudents();
				break;
			case 6: // save
				if (numStudents == 0) printf("There are no students to save yet!\n");
				else if (confirm("Overwrite the file (y/n) ? "))
					saveStudents();
				break;
			case 7: // new
				if (confirm("Delete all students from memory (y/n) ? "))
					clearStudents();
				break;
			case 8: // quit
			default: // quit
				if (confirm("Are you sure you want to quit (y/n) ? "))
				{
					printf("\nGoodbye!\n\n");
					exit(0);
				}
				break;
		}
	} while (1);
	
	return 0;
}


