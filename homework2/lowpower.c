/*	HOMEWORK 2.2
	lowpower.c:
	Prompts the user for a VOLTAGE (float) & RESISTANCE (float).
	Calculates POWER (float):
		P = V^2 / R
	If POWER EXCEEDS MAX_POWER (0.25) W, print error & start over.
	Else print calculated POWER.
	Tom Grushka
	February 5, 2016	*/

#define _CRT_SECURE_NO_WARNINGS	// allow scanf on Windows
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const float MAX_POWER = 0.25;	// Watts of MAX POWER allowed (0.25 in assignment spec)

// A few quotes from 2001: Space Odyssey to throw at the user for entering bad values
const char *QUOTES[6] = {
	"I'm sorry, Dave. I'm afraid I can't do that.",
	"I think you know what the problem is just as well as I do.",
	"This mission is too important for me to allow you to jeopardize it.",
	"I know that you and Frank were planning to fry me, and I'm afraid that's something I cannot allow to happen.",
	"Daisy, Daisy, give me your answer do.",
	"Dave, this conversation can serve no purpose anymore. Goodbye."
};

// Declare input function
float getFloat(const char *prompt);

int main(int argc, char** argv)
{
	float voltage = 0.0;	// store input voltage
	float resistance = 0.0;	// store input resistance
	float power = 0.0;		// store calculated power = voltage^2 / resistance
	int quote = 0;			// quote "counter"
	
	// Print introduction to user
	printf("Good afternoon, Dave. I am a HAL 9000 computer. I am afraid my power needs adjusting.\n");
	
	/*	Loop indefinitely if power is a "bad value":
		less than zero or greater than MAX_POWER	*/
	while (power <= 0 || power > MAX_POWER) {
		// Print instructions
		printf("Please specify a new voltage and resistance, Dave.\n");
		printf("I cannot handle more than %0.2f Watts of power, Dave.\n", MAX_POWER);
		
		/*	Input loop: keep prompting user for voltage, then
			 resistance, each until reasonable value entered. 	*/
		do {
			voltage = getFloat("Voltage: ");
		} while (voltage <= 0);
		do {
			resistance = getFloat("Resistance: ");
		} while (resistance <= 0);
		
		//	Calculate the power:	power = voltage ^2 / resistance
		power = (float)(pow(voltage, 2)) / resistance;
		
		//	Cannot exceed MAX_POWER!
		if (power > MAX_POWER)
		{
			printf("\a\a\aPower limit exceeded! %s\n\n", QUOTES[quote]);
			quote++;
			// Give the user 6 tries, then give up (exit with an error)
			if (quote == 6) exit(1);
		}
	}
	
	// Print positive feedback and result
	printf("\nVery good, Dave. That will be %0.2f Watts of power. Have a nice day!\n", power);
	
	return 0;	// We shouldn't have an error
}

/*	getFloat
	argument:	prompt (const char *)
				string to prompt the user
	return:		user input converted to float	*/
float getFloat(const char *prompt)
{
	float myFloat = 0;	// float to return
	
	printf("%s", prompt);	// Display the prompt
	scanf("%f", &myFloat);	// request input
	
	return myFloat;			// return integer
}