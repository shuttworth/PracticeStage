#include<func.h>

int main(int argc,char **argv)
{
	args_check(argc,3);
	int fdr=open(argv[1],O_RDONLY);//以读的方式打开一号管道
	if(-1==fdr)
	{
		perror("read error");
		return -1;
	}
	int fdw=open(argv[2],O_WRONLY);//以写的方式打开二号管道
	if(-1==fdw)
	{
		perror("write error");
		return -1;
	}
	printf("I am my_chat1\n");
	char buf[128]={0};
	int ret;
	fd_set rdset;
	while(1)
	{
		FD_ZERO(&rdset);//清空以前的读绑定
		FD_SET(0,&rdset);//将标准输入和读绑定
		FD_SET(fdr,&rdset);//将fdr和读绑定
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);//从1——fdr+1查找
		if(ret>0)
		{
			if(FD_ISSET(STDIN_FILENO,&rdset))//如果标准输入设置的是读绑定
			{
				memset(buf,0,sizeof(buf));
				ret=read(STDIN_FILENO,buf,sizeof(buf));
				if(0==ret)
				{
					printf("this is end\n");
					break;
				}
				write(fdw,buf,strlen(buf)-1);
			}
			if(FD_ISSET(fdr,&rdset))//如果fdr设置的是读绑定
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				if(0==ret)
				{
					printf("bye\n");
					break;
				}
				printf("%s\n",buf);
			}
		}else{
			printf("select timeout\n");
		}
	}
	close(fdr);
	close(fdw);
	return 0;
}








