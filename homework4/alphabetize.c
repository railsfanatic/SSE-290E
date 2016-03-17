/*	HOMEWORK 4.1
	Filename: alphabetize.c
	Description: Allow user to enter up to NUM_PEOPLE into
		a list, then alphabetize the list and print it.
	by Tom Grushka
	3/17/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PEOPLE 10

// define structure to hold ONE person
struct PERSON
{
	char firstName[50];
	char lastName[50];
};

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
	
	return in;
}

/*	func:	inputPerson
	in:		none
	out:	structure PERSON (not a pointer)
	desc:	inputs a single PERSON from user using inputString()
*/
struct PERSON inputPerson()
{
	struct PERSON person;
	
	// uses strcpy() to copy return from inputString to struct members
	strcpy(person.firstName, inputString("First Name: ", 50));
	strcpy(person.lastName, inputString("Last Name: ", 50));
	
	// returns the newly created struct
	return person;
}

/*	func:	printPerson
	in:		person (struct PERSON) - the person to print
			lastFirst (int) - whether to print "Last, First" or "First Last"
	out:	none
	desc:	accepts a person structure then prints it in order depending on
			lastFirst parameter
*/
void printPerson(struct PERSON person, int lastFirst)
{
	if (lastFirst) // print last name first
		printf("%s, %s\n", person.lastName, person.firstName);
	else // print first name last
		printf("%s %s\n", person.firstName, person.lastName);
}

/*	func:	printPeople
	in:		people[] (array of struct PERSON) - the array of PERSON structures
			numPeople (int) - total number of people
	out:	none
	desc:	prints header;
			calls printPerson() for each element of people[] array
*/
void printPeople(struct PERSON people[], int numPeople)
{
	int i = 0;
	// print header
	printf("\n%d people:\n========\n", numPeople);
	for (i = 0; i < numPeople; i++)
	{
		printf("%d.  ", i+1); // print number
		printPerson(people[i], 1); // print person
	}
}

/*	func:	sortPeople
	in:		people[] (pointer to array of struct PERSON) - pointer to array of people
			numPeople (int) - total number of people
	out:	none
	desc:	loops through people array and sorts it based on
			bubble sort algorithm; sorts IN PLACE rather than creating new array
*/
void sortPeople(struct PERSON *people, int numPeople)
{
	int i = 0;
	int sorted = 0;	// keep going through list if swap made
	struct PERSON tempPerson; // temp variable to store person for swapping
	
	if (numPeople < 2) return;	// no need to sort 1 person
	while (!sorted)
	{
		sorted = 1; // assume sorted; as soon as swap made, set sorted = 0 (unsorted)
		// printf("Starting over.\n"); // diagnostic print
		for (i = 0; i < numPeople - 1; i++)
		{
			/* if people[i+1] < people[i] (first and last name),
				swap the two */
			if ((strcmp(people[i+1].lastName, people[i].lastName) < 0)
				|| (strcmp(people[i+1].lastName, people[i].lastName) == 0
					&& strcmp(people[i+1].firstName, people[i].firstName) < 0))
			{
				// printf("Swapping people %d and %d\n", i, i+1); // diagnostic print
				tempPerson = people[i]; // swap using temporary variable
				people[i] = people[i+1];
				people[i+1] = tempPerson;
				sorted = 0; // we swapped, so assume we're not sorted
			}
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
		Main Program
* * * * * * * * * * * * * * * * * * * * * * * * */
int main()
{
	// declarations
	int i = 0;	// counter
	int numPeople = NUM_PEOPLE; // number of people entered
	struct PERSON people[NUM_PEOPLE]; // dimmed up to NUM_PEOPLE macro
	
	// count up to NUM_PEOPLE
	for (i = 0; i < NUM_PEOPLE; i++)
	{
		printf("Enter person #%d of %d allowed, blank to stop.\n", i+1, NUM_PEOPLE);
		people[i] = inputPerson();
		// if we enter a blank, stop
		if (strcmp(people[i].firstName, "") == 0) break;
	}
	numPeople = i; // set numPeople to i - correct whether we stopped early or not
	
	// print people (unsorted)
	printPeople(people, numPeople);
	
	// sort people
	printf("\nSorting the list...\n");
	sortPeople(people, numPeople);
	
	// print people (sorted)
	printf("Here's the sorted list:\n");
	printPeople(people, numPeople);
	
	return 0;
}


