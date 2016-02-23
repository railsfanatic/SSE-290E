#include <stdio.h>
#include <math.h>

void print_array(double ary[3][3]);
double determinant(double ary[3][3]);
void matrix_add(double ary1[3][3], double ary2[3][3], double result[3][3]);

int main(int argc, char **argv)
{
	double a[3][3] = {{7, 3, 6}, {7, M_PI, -4}, {-1, -1, 8}};
	
	double b[3][3] = {{M_PI, 2, -65}, {6.251, 2, -4.707}, {-1.902, -1.001, 0.0017}};
	
	double c[3][3];
	
	printf("Matrix A:\n");
	print_array(a);
	
	printf("det(A) = %.3f\n", determinant(a));
	
	printf("Matrix B:\n");
	print_array(b);
	
	printf("det(B) = %.3f\n", determinant(b));
	
	matrix_add(a, b, c);
	
	printf("Matrix A + Matrix B:\n");
	print_array(c);
	
	printf("det([A]+[B]) = %.3f\n", determinant(c));
	
}

void matrix_add(double ary1[3][3], double ary2[3][3], double result[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = ary1[i][j] + ary2[i][j];
		}
	}
}

double determinant(double ary[3][3])
{
	double det = (
		  ary[0][0] * (ary[1][1] * ary[2][2] - ary[1][2] * ary[2][1])
		- ary[0][1] * (ary[1][0] * ary[2][2] - ary[1][2] * ary[2][0])
		+ ary[0][2] * (ary[1][0] * ary[2][1] - ary[1][1] * ary[2][0])
    );
	return det;
}

void print_array(double ary[3][3])
{
	printf(" _\t\t\t\t_\n");
	for (int i = 0; i < 3; i++)
	{
		printf((i == 2) ? "|_\t" : "|\t");
		for (int j = 0; j < 3; j++)
		{
			printf("%.3f\t", ary[i][j]);
		}
		printf((i == 2) ? "_|\n" : " |\n");
	}
	printf("\n");
}
