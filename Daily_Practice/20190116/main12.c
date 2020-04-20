#include <stdio.h>

int main()
{
	int fd;
	long double ld=8;	
	double d=0.345678;
	printf("size=%ld\n",sizeof(ld));
	printf("%Lf\n",ld);
	printf("%f\n",d);
	return 0;
}
