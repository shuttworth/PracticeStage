#include "func.h"
//通过fork创建子进程，然后父进程通过wait回收，同时拿到子进程的返回值
int main()
{
	if(!fork())
	{
		printf("I am child,pid=%d,ppid=%d\n",getpid(),getppid());
		return 5;
	}else{
		printf("I am parent\n");//父进程先执行,创建子进程，父进程的返回值是进程号，子进程的返回值是0
		pid_t pid;
		int status;
		pid=wait(&status);//父进程执行到这一步，wait，等到子进程给了返回值以后再接着执行。
		if(WIFEXITED(status))
		{
			printf("child exit code=%d\n",WEXITSTATUS(status));
		}else{
			printf("child crash\n");
		}
		return 0;
	}
}
