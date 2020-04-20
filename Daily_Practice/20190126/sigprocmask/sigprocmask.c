#include <func.h>

//通过sigprocmask阻塞2号信号，睡眠5秒后，解除阻塞，2号信号得到执行
//在睡眠后，解除阻塞之前，通过sigpending检测是否有信号挂起

int main()
{
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask,SIGINT);
    int ret;
    ret=sigprocmask(SIG_BLOCK,&mask,NULL);
    if(-1==ret)
    {
        perror("sigprocmask");
        return -1;
    }
    printf("sigprocmask block success\n");//关键代码
    sleep(5);
    sigset_t pendSignal;
    sigpending(&pendSignal);
    if(sigismember(&pendSignal,SIGINT ))
    {
    
        printf("SIGINT is pending\n");
    }else {
        printf("SIGINT is not pending\n");
    }


    sigprocmask(SIG_UNBLOCK,&mask,NULL);
    return 0;
}

