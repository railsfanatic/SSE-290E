#include <stdio.h>

float delta_A(float x1, float x2, float y1, float y2)
{
	return (0.5 * (x2 - x1) * (y1 + y2));
}

float fn_y(float x)
{
	return 3 / x + 5;
}

int main()
{
	float low = 1.0;
	float high = 10.0;
	
	float delta_x = 0.5;
	int size = (high - low) / delta_x + 1;
	
	printf("size = %d\n", size);
	
	float x[size], y[size], dA[size];
	dA[0] = 0;
	int i = 0;
	float sum = 0;
	
	printf("%5s  %10s  %10s  %10s  %10s\n", "i", "x[i]", "y[i]", "dA[i]", "\u03a3");
	
	for (i = 0; i < size; i++)
	{
		x[i] = delta_x*i + low;
		y[i] = fn_y(x[i]);
		
		if (i > 0) dA[i] = delta_A(x[i-1], x[i], y[i-1], y[i]);
		
		sum += dA[i];
		printf("%5d  %10.5f  %10.5f  %10.5f  %10.5f\n", i, x[i], y[i], dA[i], sum);
	}
	return 0;
}
