#include "func.h"
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("arg error");
		return -1;
	}

	
	DIR *pdir;
	pdir=opendir(argv[1]);
	if(NULL==pdir)
	{
		perror("opendir error");
		return -1;
	}

	struct stat st;
	struct dirent *p;
	char pname[128]={0};
	while((p=readdir(pdir)!=NULL)
{
			if(!strcmp(p->d_name,".")||!strcmp(p->d_name,".."))
			{	continue;}
			sprintf(pname,"%s%s%s",argv[1],"/",p->d_name);
			stat(pname,&st);
			char c[20]={0};
			int s=0;
			args_check(argc,2);
			int ret;
			struct stat buf;
			ret=stat(argv[1],&buf);
			if(-1==ret)
			{
			perror("stat");
			return -1;
			}
			printf("%x %ld %s %s %ld %ld %ld %s\n",buf.st_mode,buf.st_nlink,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,buf.st_size,buf.st_blksize,buf.st_blocks,ctime(&buf.st_mtime));
			return 0;
			}

			
			closedir(pdir);		
			}
