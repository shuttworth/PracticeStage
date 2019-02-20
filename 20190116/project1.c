#include<stdio.h>
#define MAX 100
#define max(a,b)((a)>(b)?(a):(b))
int main()
{
	printf("MAX=%d\n",MAX);
	printf("max(3,4)=%d\n",max(3,4));
}
