#include <stdio.h>
#include <math.h>

int operation(int m, int n)
{
 int temp=0;
 temp =m;
 m=n;
 n=temp;
 temp=pow(m,2)+pow(n,3);
 return temp;
}

int main()
{
	int a=3;
	 int b=5;
	 printf("%d\n",operation(a,b));
	return 0;
}