/*	HOMEWORK 4.3 & 4.4
	Filename: students.c
	Description: Allows user to enter up to NUM_STUDENTS
		of student data structs, then allows user to:
			- print list of students
			- find student by last name (case insensitive)
			- print info for a student
		ADDITIONS:
			- edit user (with existing value defaults)
			- sort database asc/desc by any of the 4 fields
			- save data to file (same folder as exe)
			- load data from file (same folder as exe)
			- clear students[] and reset # of students to 0
	by Tom Grushka
	3/17 - 3/20/2016
*/

#ifdef _MSC_VER
	// Quiet security warnings about strcmp(), scanf(), etc. on Windows
	#define _CRT_SECURE_NO_WARNINGS
	// Quiet deprecation warnings about strdup(), etc. on Windows
	#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#include <stdio.h>
#include <string.h>	// string funcs
#include <time.h>	// date/time types & funcs
#include <stdlib.h>	// malloc(), atoi(), exit()
#include <ctype.h>	// isspace(), toupper(), tolower()

#define MAX_STUDENTS 100

// global declarations

struct STUDENT	// structure to store a student record
{
	char firstName[32];		// first name
	char lastName[32];		// last name
	int completedCredits;	// # credits completed
	time_t enrollmentDate;	// date they enrolled
};

// global students[] array of STUDENT structs and MAX_STUDENTS elements
struct STUDENT students[MAX_STUDENTS];

// global integer of the total # of students in students[]
int numStudents = 0;

/*	saveStudents
	save from global students[] array into binary file
	in:  none
	out: 0 if success, 1 if failure
*/
int saveStudents()
{
	// declarations
	int i;			// loop counter
	FILE *file;		// pointer to file
	
	// open students.dat file for binary writing in current folder
	file = fopen("students.dat", "wb");
	if (!file)
	{
		printf("Unable to open file!\n");
		return 1;
	}
	
	// first, write # of students to top of file
	printf("Saving %d students ...\n", numStudents);
	fwrite(&numStudents, sizeof(int), 1, file);
	
	// loop through students, write to file one "record" at a time
	for (i = 0; i < numStudents; i++)
		fwrite(&students[i], sizeof(struct STUDENT), 1, file);
	
	// close the file
	fclose(file);
	return 0;
}

/*	loadStudents
	load students from binary file into global students[] array
	in:  none
	out: 0 if success, 1 if failure
*/
int loadStudents()
{
	// declarations
	int i;			// loop counter
	FILE *file;		// pointer to file
	
	// open students.dat file for binary reading in current folder
	file = fopen("students.dat", "rb");
	if (!file)
	{
		printf("Unable to open file!\n");
		return 1;
	}
	
	// first, read number of students
	fread(&numStudents, sizeof(int), 1, file);
	
	printf("\nLoading %d students ...\n", numStudents);
	
	// loop until # of students, read one "record" at a time
	for (i = 0; i < numStudents; i++)
		fread(&students[i], sizeof(struct STUDENT), 1, file);
	
	// close the file
	fclose(file);
	return 0;
}

/*	stripWhitespace
	remove leading and trailing whitespace from a string
	*in place* (used in inputString() func)
	in:  string (pointer to char) - string to strip
	out: none (updates string "in place")
	source: http://stackoverflow.com/questions/352055/best-algorithm-to-strip-leading-and-trailing-spaces-in-c
*/
void stripWhitespace(char *string) {
	// remove leading spaces
	// increment string pointer until we reach a "non space"
	const char* firstNonSpace = string;
	while (*firstNonSpace != '\0' && isspace(*firstNonSpace))
		++firstNonSpace;
	
	// get length of string we just stripped leading spaces from
	size_t len = strlen(firstNonSpace) + 1;
	
	// move firstNonSpace string into memory of string
	memmove(string, firstNonSpace, len);
	
	// get the end of the string
	char* endOfString = string + len;
	
	// step from the end of the string to last "non space"
	// and decrement the endOfString position
	if (len < 2) // bypass obscure isspace() bug on Windows
		while (string <= endOfString && isspace(*endOfString))
			--endOfString;
	
	// terminate the string after the last "non space"
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
char *inputString(const char *prompt, int size)
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
	
	// remove whitespace from beginning and end of string
	stripWhitespace(in);
	
	return in;
}

/*	inputDate
	get string input from user, convert to time_t (date/time)
	in:  prompt (const char *) - string to prompt user
	out: time_t - C date/time converted from user input
*/
time_t inputDate(const char *prompt)
{
	// declarations
	int m = 0;		// user entered month
	int d = 0;		// user entered day
	int y = 0;		// user entered year
	char tempDate[10];	// holds user string
	struct tm date = {0};	// struct used to convert string to time_t
	
	// loop until valid date entered
	do {
		// get user string into tempDate
		strcpy(tempDate, inputString(prompt, 10));
		if (strcmp(tempDate, "") == 0) return mktime(&date);
		
		// extract m, d, y from user string
		sscanf(tempDate, "%d/%d/%d", &m, &d, &y);
		
		// convert 2-digit year to 4-digit year
		if (y < 100 && y >= 30) y += 1900;
		if (y < 30) y += 2000;
		
		// validate m, d, and y; repeat input if invalid
	} while ((m < 1 || m > 12) ||
			(d < 1 || d > 31) ||
			(y < 1900 || y > 2100));
	
	// use a (struct tm) to "construct" date
	date.tm_mon = m - 1;
	date.tm_mday = d;
	date.tm_year = y - 1900;
	
	// use mktime to convert date to a time_t & return
	return mktime(&date);
}

/*	inputInteger
	get string input from user, convert to integer
	in:  prompt (const char *) - string to prompt user
	out: integer - converted from user input string
*/
int inputInteger(const char *prompt)
{
	return atoi(inputString(prompt, 10));
}


/*	downcase
convert a string to lowercase
in:  s (pointer to string)
out: pointer to copy of s, in lowercase
*/
char *downcase(char *s)
{
	// allocate copy of string with new pointer
	char *d = (char *)malloc(strlen(s) * sizeof(char));
	d = strdup(s);	// duplicate *s into *d
	char *p = d;	// create another pointer to *d
					// loop d and lowercase all chars in the duplicate
	for (; *d; ++d) *d = tolower(*d);
	// because d is "gone", return p
	return p;
}

/*	confirm
	prints a prompt and asks user to enter y/n
	in:  prompt (const char *) - string to prompt user
	out: 1 if Y/y, 0 otherwise
*/
int confirm(const char *prompt)
{
	char *confirmation;

	// get first character of string input
	confirmation = inputString(prompt, 2);
	// if Y or y, return 1; else return 0
	if (strcmp(confirmation, "y") == 0) return 1;
	else return 0;
}

/*	addStudents
	function with loop to add students one at a time
	in:  none
	out: none
*/
void addStudents()
{
	// declarations
	char firstName[32];		// store input first name
	char lastName[32];		// store input last name
	int completedCredits;	// store input completed credits
	time_t enrollmentDate;	// store input enrollment date
	struct STUDENT *s;		// pointer to a student record
	
	// print header
	printf("Add Students\n============\n\n"
		"Start entering students. Leave first name blank to stop.\n\n");
	
	// outer loop for entering another student
	do {
		// inner loop for repeating incorrect entry
		do {
			// print # entering
			printf("Student #%d\n", numStudents + 1);
			
			// get input from user
			strcpy(firstName, inputString("First name: ", 32));
			if (strcmp(firstName, "") == 0) return;
			
			strcpy(lastName, inputString("Last name: ", 32));
			if (strcmp(lastName, "") == 0) return;
			
			completedCredits = inputInteger("Completed credits: ");
			enrollmentDate = inputDate("Enrollment date (mm/dd/yyyy): ");
			
			// display input info back to user
			printf("\nFirst name: %s\n"
				"Last name: %s\n"
				"Completed credits: %d\n"
				"Enrollment date: %s\n",
					firstName,
					lastName,
					completedCredits,
					ctime(&enrollmentDate));
			
			// repeat if info incorrect
		} while (!confirm("Info correct (y/n) ?"));
		
		// get pointer to new student
		s = &students[numStudents];
		
		// put info into array at pointer
		strcpy(s->firstName, firstName);
		strcpy(s->lastName, lastName);
		s->completedCredits = completedCredits;
		s->enrollmentDate = enrollmentDate;
		
		// increment # of students
		numStudents ++;
	
	// loop if user wants to input another student
	} while (confirm("Add another student (y/n) ?"));
}

/*	formatDate
	formats a date using strftime in mm/dd/yyyy format
	in:  d (time_t) - date to format time_t encoded
	out: pointer to char - formatted date string
*/
char *formatDate(time_t d)
{
	// allocate memory for the formatted date
	char *s = malloc(10 * sizeof(char));
	// format the date in mm/dd/yyyy
	strftime(s, 10, "%m/%d/%Y", localtime(&d));
	return s;	// return pointer to formatted date string
}

/*	printStudent
	print details for given student
	(useful when we add more data fields)
	in:  s (pointer to struct STUDENT) - student record to print
	out: none
*/
void printStudent(struct STUDENT *s)
{
	printf("%s, %s\n", s->lastName, s->firstName);
	printf("Date enrolled: %s\n", formatDate(s->enrollmentDate));
	printf("Completed credits: %d\n", s->completedCredits);
}

/*	formatName
	takes a first and last name as input and returns
	them concatenated by user preference
	in:  fn (pointer to char) - first name
	     ln (pointer to char) - last name
	     lnf (int) - last name first?
	out: pointer to char - concatenated name
*/
char *formatName(char *fn, char *ln, int lnf)
{
	// allocate space for concatenated string
	char *s = malloc(66 * sizeof(char));
	if (lnf)	// last name first:
		sprintf(s, "%s, %s", ln, fn);	// concat to new string
	else		// first name last:
		sprintf(s, "%s %s", fn, ln);
	return s;
}

/*	editStudent
	edit an existing student, and display details
	as defaults for input
	in:  pointer to a student to edit
	out: none
*/
void editStudent(struct STUDENT *s)
{
	char firstName[32];		// store input first name
	char lastName[32];		// store input last name
	int completedCredits;	// store input credits
	time_t enrollmentDate;	// store input enrollment date
	// store an "empty date" to compare with entered date to indicate no change
	time_t noDate = mktime(&(struct tm){0});
	
	do {
		// display what # student we're editing
		printf("\nEditing Student #%d\n", numStudents + 1);
		
		// input first name & update only if input not empty
		printf("First name: [%s] ", s->firstName);
		strcpy(firstName, inputString("", 32));
		if (strcmp(firstName, "") == 0) strcpy(firstName, s->firstName);
		
		// input last name & update only if input not empty
		printf("Last name: [%s] ", s->lastName);
		strcpy(lastName, inputString("", 32));
		if (strcmp(lastName, "") == 0) strcpy(lastName, s->lastName);
		
		// input completed credits & update only if input not empty
		printf("Completed credits: [%d] ", s->completedCredits);
		completedCredits = inputInteger("");
		if (completedCredits == 0) completedCredits = s->completedCredits;
		
		// input enrollment date & update only if input not empty
		printf("Enrollment date (mm/dd/yyyy): [%s] ", formatDate(s->enrollmentDate));
		enrollmentDate = inputDate("");
		// since inputDate returns a time_t, we must check against an "empty" date
		if (difftime(enrollmentDate, noDate) == 0) enrollmentDate = s->enrollmentDate;
		
		// print details entered
		printf("\nFirst name: %s\n"
			"Last name: %s\n"
			"Completed credits: %d\n"
			"Enrollment date: %s\n",
				firstName,
				lastName,
				completedCredits,
				ctime(&enrollmentDate));
		// confirm with user whether info correct, repeat input if not
	} while (!confirm("\nInfo correct (y/n) ?"));
	
	// store entered data back into the record pointed to by s
	strcpy(s->firstName, firstName);
	strcpy(s->lastName, lastName);
	s->completedCredits = completedCredits;
	s->enrollmentDate = enrollmentDate;
}

/*	listStudents
	print a list of all students in global students[] array
	in:  none
	out: none
*/
void listStudents()
{
	// declarations
	struct STUDENT *s;	// pointer to "current" student
	int i;				// loop counter
	
	// print headers
	printf("LIST ALL STUDENTS\n\n");
	printf(	"  #  Student Name\t\t\tEnrolled    Credits\n"
			"===  ============\t\t\t==========  =======\n");
	
	// loop through all students
	for (i = 0; i < numStudents; i++)
	{
		s = &students[i];	// set pointer to "current" student
		// print the student's data
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
	
	// ask user whether to view/edit the details
	i = inputInteger("Type # to view/edit, or blank to return to menu. ");
	// if not, return
	if (i < 1 || i > numStudents) return;
	
	// print the student's details
	// (if we had more fields, they would be displayed now)
	printf("\n");
	printStudent(&students[i-1]);
	printf("\n");
	
	// edit student if user wishes to do so
	if (confirm("Edit this student (y/n) ? "))
		editStudent(&students[i-1]);
}

/*	sortStudents
	sort the array of students based on user preference
	(uses simple bubble sort algorithm)
	in:  none
	out: none
*/
void sortStudents()
{
	// declarations
	char sortField;		// user entered field to sort
	char fieldName[20];	// name of the field to sort
	int i = 0;			// loop counter for sorting
	int sorted = 0;		// repeat loop for bubble sort
	int swap = 0;		// whether to swap students[i] & students[i+1]
	int desc = 0;		// if we're sorting in descending order
	struct STUDENT tempStudent;	// temp struct to store student for swapping
	
	// no need to sort only one or 0 students!
	if (numStudents < 2) return;
	
	// print menu choices
	printf("Sort by:\t"
		"L) Last Name\n\t\t"
		"F) First Name\n\t\t"
		"E) Enrollment Date\n\t\t"
		"C) Completed Credits ? ");
	
	// get sort field from user
	sortField = toupper(inputString("", 2)[0]);
	
	// ask user whether to sort in descending order
	desc = confirm("\nDescending (just hit Enter for ascending) (y/n) ? ");
	
	// set the fieldName for display back to user
	switch (sortField)
	{
		case 'F':
			strcpy(fieldName, "First name");
			break;
		case 'E':
			strcpy(fieldName, "Enrollment date");
			break;
		case 'C':
			strcpy(fieldName, "Completed credits");
			break;
		case 'L':
		default:
			strcpy(fieldName, "Last name");
			break;
	}
	
	// print back to user how we are sorting
	printf("\nSorting by: %s, %s ...\n\n",
		fieldName, desc ? "Descending" : "Ascending");
	
	while (!sorted)		// repeat loop for bubble sort
	{
		sorted = 1;		// "assume" sorted until we swap
		// loop through all students - 1
		// (because we're swapping [i] with [i+1])
		for (i = 0; i < numStudents - 1; i++)
		{
			swap = 0;	// do not swap unless flagged
			switch (sortField)	// check by field:
			{
				case 'F': // first name
					swap = ((strcmp(students[i+1].firstName, students[i].firstName) < 0)
						|| (strcmp(students[i+1].firstName, students[i].firstName) == 0
						&& strcmp(students[i+1].lastName, students[i].lastName) < 0));
					break;
				case 'E': // enrollment date
					swap = (difftime(students[i].enrollmentDate, students[i+1].enrollmentDate) > 0);
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
			/*	XOR desc ^ swap:
				if swap == 1, order must be swapped for ascending;
				if swap == 0, order must be swapped for descending  */
			if (desc ^ swap)
			{
				// swap students[i] and students[i+1] using temp variable
				tempStudent = students[i];
				students[i] = students[i+1];
				students[i+1] = tempStudent;
				sorted = 0;	// we had to swap, so repeat the loop
			}
		}
	}
	// when done sorting, print the sorted student list
	listStudents();
}

/*	findStudent
	routine to find a student (by last name)
	in:  none
	out: none
*/
void findStudent()
{
	// declarations
	int i = 0;					// loop counter
	char *findLastName;			// last name to search
	char *lastName;				// holds "current" student last name in loop
	int found[MAX_STUDENTS];	// array to store indices of found students
	int numFound = 0;			// # of students found
	
	// print header
	printf("FIND STUDENT BY LAST NAME\n\n");
	
	// loop until user quits
	do {
		numFound = 0;		// reset # found to 0
		
		// input last name and convert to lowercase
		findLastName = downcase(inputString("Enter partial or entire last name: ", 32));
		printf("\n\nSearching ... ");
		
		// loop through all student records
		for (i = 0; i < numStudents; i++)
		{
			// set lastName to lowercase of "current" student last name
			lastName = downcase(students[i].lastName);
			
			// if the student last name *contains* the text the user entered
			if (strstr(lastName, findLastName) != NULL)
			{
				found[numFound] = i;	// add student to found students array
				numFound ++;	// increment counter
			}
		}
		// if we didn't find any
		if (numFound == 0) printf("No matches found.\n");
		
		else	// we did find at least one
		{
			// print # students found
			printf("Found %d students:\n\n", numFound);
			
			// loop through found students & print each
			for (i = 0; i < numFound; i++)
			{
				printStudent(&students[found[i]]);
				printf("\n");
			}
		}
		
		// ask user for another search
	} while (confirm("Find another (y/n) ? "));
}

/*	clearStudents
	erases data array and resets # of students to 0
	(assumes already confirmed by user)
	in:  none
	out: none
*/
void clearStudents()
{
	int i = 0;
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		memset(&students[i], 0, sizeof(struct STUDENT));
	}
	numStudents = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
		Main Program:
		Display menu, get and run user choice.
* * * * * * * * * * * * * * * * * * * * * * * * */
int main()
{
	int choice = 0;	// store user selection
	int quit = 0;	// flag to end program
	
	// print the menu, loop until user quits
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
		
		// input the user selection
		choice = inputInteger("Choice: ");
		printf("\n");
		
		// run the appropriate function based on user choice
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
				if (numStudents == 0 || confirm("LOAD file and LOSE all students in memory (y/n) ? "))
					loadStudents();
				break;
			case 6: // save (only if students[] is not empty)
				if (numStudents == 0) printf("There are no students to save yet!\n");
				else if (confirm("OVERWRITE the file (y/n) ? "))
					saveStudents();
				break;
			case 7: // new
				if (confirm("DELETE all students from memory (y/n) ? "))
					clearStudents();
				break;
			case 8: // quit
			default: // quit
				if (confirm("QUIT and LOSE all data in memory (y/n) ? "))
				{
					printf("\nThank you and goodbye!\n\n");
					quit = 1;
				}
				break;
		}
	} while (quit == 0);	// keep repeating until user chooses to quit
	
	// quit = 1: end program successfully
	return 0;
}