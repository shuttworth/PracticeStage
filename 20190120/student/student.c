#include<func.h>

typedef struct student{
	int iNum;
	char name[20];
	float score;
}Student,*pStu;

int main(int argc,char** argv){
	args_check(argc,2);
	int ret=0,i;
	int fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		perror("error open");
		exit(-1);
	}

	Student s[3]={{151010,"lilei",95},{151012,"hanmeimei",87.5},{151014,"geben",88}};
	char buf[100];
	for(i=0;i<3;i++)
	{memset(buf,0,sizeof(buf));
		sprintf(buf,"%d %s %f",s[i].iNum,s[i].name,s[i].score);

		int wd=write(fd,buf,sizeof(buf));
		if(-1==wd)
		{
			perror("error write");
			return -1;
		}

	}
	lseek(fd,0,SEEK_SET);
	while((ret=read(fd,buf,sizeof(buf)))>0)
	{
		puts(buf);
		memset(buf,0,sizeof(buf));
	}
	close(fd);
}

