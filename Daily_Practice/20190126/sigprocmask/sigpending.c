#include <func.h>
//2号是sigint，3号是sigquit
//sigaction实现2号信号，屏蔽3号信号的执行效果，同时在2号信号的信号处理流程中
//判断3号信号是否被挂起

int main()
{
    sigset_t mask;
    sigemptyset(&mask);//清空信号集合
   signal(SIGINT,SIG_IGN);
    sigaddset(&mask,SIGQUIT);//把sigint信号添加到mask集合里
    int ret;
    ret=sigprocmask(SIG_BLOCK,&mask,NULL);//将mask的信号集合全部添加到进程原有的阻塞信号集合中
    if(-1==ret)
    {
        perror("sigprocmask");
        return -1;
    }
    printf("sigprocmask block success\n");//关键代码
    sleep(3);
    sigset_t pend;
    sigemptyset(&pend);
    sigpending(&pend);
    if(sigismember(&pend,SIGQUIT))
    {
        printf("SIGQUIT  have come\n");
    }else{
        printf("SIGQUIT  don't come\n");
    }
    sigprocmask(SIG_UNBLOCK,&mask,NULL);//从原有的阻塞集合中移除mask的
    return 0;
}

