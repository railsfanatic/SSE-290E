#include <stdio.h>

int main()
{
	const float voltage = 120;
	float power = 0;
	float current = 0;
	
	printf("Enter the selected power rating\n");
	scanf("%f",&power);
	current=power/voltage;
	 
	while (power > 3.6)
	{
		printf("Current too high, please try again.\n");
		scanf("%f", &power);
	}
	
	current = power / voltage;
	
	printf("The selected power rating %0.2f results in current %0.2f A and is within the limits\n", power, current);
	return 0;
}
