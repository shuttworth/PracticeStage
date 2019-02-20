#include <func.h>

void sigfunc(int signum,siginfo_t *p,void *p1)
{
    printf("%d is coming\n",signum);
}
int main()
{
    struct sigaction act;//定义结构体act
    memset(&act,0,sizeof(act));//结构体初始化，全部置0
    act.sa_sigaction=sigfunc;
    act.sa_flags=SA_NODEFER;
    int ret;
    ret=sigaction(SIGINT,&act,NULL);
    sigaction(SIGTSTP,&act,NULL);//sigaction实现信号 不断重入 的执行效果
    if(-1==ret)
    {
        perror("sigaction error");
        return -1;
    }
    while(1);
    return 0;
}

