#include<func.h>

int main(int argc,char *argv[])
{
	args_check(argc,3);
	int fd=open("argv[1]",O_RDWR);
	int fd3=open("argv[2]",O_RDWR);
	if(fd==-1)
	{
		perror("error open");
		exit(-1);
	}
	//printf("\n");
	close(1);
	int fd2=dup(fd);
	close(fd);
	printf("hello");//
	fflush(stdout);
	if(fd3==-1)
	{
		perror("error open");
		exit(-1);
	}
	close(2);
	int fd4=dup(fd3);
	close(fd3);
	printf("world");
	close(fd4);
}
