#include <stdio.h>

int main(int argc,char* argv[])
{
	printf("I am printf\n");
	FILE *fp;
	fp=fopen(argv[1],"rb+");
	if(NULL==fp)
	{
		perror("fopen");
		return -1;
	}
	fputc('c',fp);
	return 0;
}
