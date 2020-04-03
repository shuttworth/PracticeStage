#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include <iostream>

using std::cout;
using std::endl;


void *  threadFunc(void *)
{
    int cnt = 10;
    while(cnt--)
    {
        printf("sub thread %u\n",(unsigned int)pthread_self() );
        //sleep(1);
    }
    return NULL;
}








int main()
{
    printf("main pthread start\n");
    pthread_t pthid = 0;
    pthread_create(&pthid,NULL,threadFunc,NULL);
    printf("main pthread %u, 子线程 %u\n",(unsigned int)pthread_self(),(unsigned int)pthid);
    int cnt = 10;
    while(cnt--)
    {
        printf("main thread %u\n",(unsigned int)pthread_self() );
        //sleep(1);
    }
    pthread_join(pthid,NULL);
    printf("main pthread end\n");
    return 0;
}

