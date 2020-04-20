#include <func.h>

int main()
{
	int fds[2]={0};//用来存放无名管道的读端和写端
	pipe(fds);
	if(!fork())//子进程
	{
		close(fds[1]);//关闭写端
		char buf[128]={"i love you"};
		read(fds[0],buf,sizeof(buf));//读到buf里
		printf("%s\n",buf);//打印出来
	}else{
		close(fds[0]);//关闭读端
		write(fds[1],"hello",5);
		wait(NULL);
		return 0;
	}
}

