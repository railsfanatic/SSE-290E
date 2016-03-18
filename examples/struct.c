#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { A, B, C, D } APT_TYPE;

struct LEASE
{
	char firstName[32];
	char lastName[32];
	char ssn[11];
	float monthlyIncome;
	APT_TYPE apartmentType;
	char startDate[11];
	char endDate[11];
};

struct LEASE changeApartmentType(struct LEASE lease, APT_TYPE newAptType)
{
	lease.apartmentType = newAptType;
	return lease;
}

char *aptTypeDisplay(APT_TYPE aptType)
{
	switch (aptType)
	{
		case A:
			return "1-bed 1-bath";
		case B:
			return "2-bed 1-bath";
		case C:
			return "2-bed 2-bath";
		case D:
			return "3-bed 2-bath";
	}
	return "";
}

void loadData(struct LEASE *leases, int num)
{
	strcpy(leases[0].firstName, 	"Tom");
	strcpy(leases[0].lastName, 		"Grushka");
	strcpy(leases[0].ssn, 			"738-28-3912");
		   leases[0].monthlyIncome = 8592.25;
		   leases[0].apartmentType = D;
	strcpy(leases[0].startDate, 	"03/15/2016");
	strcpy(leases[0].endDate, 		"03/14/2017");
	
	strcpy(leases[1].firstName, 	"Mike");
	strcpy(leases[1].lastName, 		"Smith");
	strcpy(leases[1].ssn, 			"725-12-2345");
		   leases[1].monthlyIncome = 2125.00;
		   leases[1].apartmentType = A;
	strcpy(leases[1].startDate, 	"03/02/2016");
	strcpy(leases[1].endDate, 		"03/01/2017");
	
	strcpy(leases[2].firstName, 	"Sue");
	strcpy(leases[2].lastName, 		"Johnson");
	strcpy(leases[2].ssn, 			"582-53-1859");
		   leases[2].monthlyIncome = 5132.00;
		   leases[2].apartmentType = B;
	strcpy(leases[2].startDate, 	"02/01/2016");
	strcpy(leases[2].endDate, 		"01/31/2017");
}

int findByLastName(char *lastName, struct LEASE *leases, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (strcmp(lastName, leases[i].lastName) == 0)
			return i;
	}
	return -1;
}

int findByFirstName(char *firstName, struct LEASE *leases, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (strcmp(firstName, leases[i].firstName) == 0)
			return i;
	}
	return -1;
}

void printLease(struct LEASE l)
{
	printf("First Name: \t%s\n",	l.firstName);
	printf("Last Name: \t%s\n", 	l.lastName);
	printf("SSN: \t\t%s\n",			l.ssn);
	printf("Monthly Income: $%0.2f\n", l.monthlyIncome);
	printf("Apartment Type: %s\n", 		aptTypeDisplay(l.apartmentType));
	printf("Start Date: \t%s\n", 		l.startDate);
	printf("End Date: \t%s\n", 		l.endDate);
	printf("\n");
}

void printLeases(struct LEASE *leases, int num)
{
	for (int i = 0; i < num; i++)
	{
		printLease(leases[i]);
	}
}

int main()
{
	const int NUM_LEASES = 10;
	struct LEASE leases[NUM_LEASES];
	
	loadData(leases, NUM_LEASES);
	
	// printLeases(leases, NUM_LEASES);
	
	int record = -1;
	record = findByLastName("Smith", leases, NUM_LEASES);
	
	if (record >= 0)
	{
		printLease(leases[record]);
		
		leases[record] = changeApartmentType(leases[record], B);
		
		printLease(leases[record]);
	}
	
	return 0;
}


