#include "func.h"

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("arg error!");
		return -1;
	}
	DIR *pdir = opendir(argv[1]);
	if(NULL==pdir)
	{
		printf("路径有错!");
		return -1;
	}

	struct dirent *p;
	struct stat st;
	char pname[128];
	while((p=readdir(pdir))!=NULL)
	{	
		if(!strcmp(p->d_name,".")||!strcmp(p->d_name,"..")) continue;
		sprintf(pname,"%s%s%s",argv[1],"/",p->d_name);
		stat(pname,&st);
		char c[20] = {0};
		int s = 0;
		int mode = st.st_mode;
		
		if(((mode>>12)==4))
		{
			c[s++] = 'd';
		}else
		{
			c[s++] = '-';
		}
		for(int i=2;i>=0;i--)
		{
			for(int j=2;j>=0;j--)
			{
				int m = mode&(1<<(3*i+j));
				if(m>0)
				{
					if(j==2)
					{
						c[s++] = 'r';
					}else if(j==1)
					{
						c[s++] = 'w';
					}else
					{
						c[s++] = 'x';
					}

				}else
				{
					c[s++]='-';
				}
			}
		}
		char t1[20];
		   strcpy(t1,ctime(&st.st_mtime));
		char t2[20];
		strncpy(t2,t1+4,12);
		printf("%7ld %s %ld %s %s %4ld %4ld %2ld %s %s\n",st.st_ino,c,st.st_nlink,getpwuid(st.st_uid)->pw_name,getgrgid(st.st_gid)->gr_name,st.st_size,st.st_blksize,st.st_blocks,t2,p->d_name);
		
	}
	return 0;

}
