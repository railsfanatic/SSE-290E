#include <stdio.h>
#include <math.h>

void swap(int *n, int *m)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}

int func(void)
{
	double d;
	d = 4.6;
	return d; // return integer
}

double addition(double a, double b)
{
	double s;
	s = a + b;
	return s;
}

double hypotenuse(double a, double b)
{
	double hypo;
	hypo = sqrt(pow(a, 2) + pow(b, 2));
	return hypo;
}

int main()
{
	int m = 3;
	int n = 4;
	printf("m = %d, n = %d\n", m, n);
	swap(&m, &n);
	printf("m = %d, n = %d\n", m, n);
	
	
	/*
	double a, b, h;
	a = 6;
	b = 8;
	h = hypotenuse(a, b);
	printf("Side A = %lf, Side B = %lf, Hypotenuse = %lf\n", a, b, h);
	*/
	return 0;
}
