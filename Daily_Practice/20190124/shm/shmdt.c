#include <func.h>

int main()
{
    int shmid=shmget(1000,4096,IPC_CREAT|0600);//共享内存段的创建,0600是权限控制
    if(-1==shmid)
    {
        perror("shmget");
        return -1;
    }
    char *p;
    p=(char*)shmat(shmid,NULL,0);//共享内存段映射到进程空间
    if((char*)-1==p)
    {
        perror("shmat");
        return -1;
    }
    int ret=shmdt(p);//将共享内存段与进程空间分离
    if(-1==ret)
    {
        perror("shmdt");
        return -1;
    }
    while(1);
    return 0;
}
