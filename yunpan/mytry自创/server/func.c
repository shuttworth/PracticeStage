#include "head.h"
#include "factory.h"
#include "tranfile.h"
#include "work_que.h"

int func_remove(int new_fd,char *buf)
{
    int ret,i=2;
char p[512]={0};
while(buf[i]==' ')
{
	i++;
}
printf("ok\n");
ret=unlink(buf+i);
if(-1==ret)
{
	perror("unlink");
	send(new_fd,"error please input again: ",27,0);
	return 1;
}
printf("hello\n");
	sprintf(p,"%s$",getcwd(NULL,0));
	send(new_fd,p,strlen(p),0);
return 0;
}
