#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include <iostream>

using std::cout;
using std::endl;


int gNumber=1000;
pthread_mutex_t mutex1;
pthread_cond_t cond1;
bool flag=true;



void *  threadFunc1(void *)
{//flag为true，正常工作，结束后置为false，唤醒
 //flag为false，挂起等待唤醒   
    int cnt = 10;
    while(cnt--)
    {
        pthread_mutex_lock(&mutex1);
        while(flag==false) 
            pthread_cond_wait(&cond1,&mutex1);
        printf("sub thread %u , gNumber = %d\n",(unsigned int)pthread_self(),gNumber );
        --gNumber;
        sleep(1);
        flag=false;
        pthread_mutex_unlock(&mutex1);
        pthread_cond_signal(&cond1);
    }
    return NULL;
}


void *  threadFunc2(void *)
{//flag为false，正常工作，结束后置为true，唤醒
 //flag为true，挂起等待唤醒   
    int cnt = 10;
    while(cnt--)
    {
        pthread_mutex_lock(&mutex1);
        while(flag==true) 
            pthread_cond_wait(&cond1,&mutex1);
        printf("sub thread %u , gNumber = %d\n",(unsigned int)pthread_self(),gNumber );
        --gNumber;
        flag=true;
        sleep(1);
        pthread_mutex_unlock(&mutex1);
        pthread_cond_signal(&cond1);
    }
    return NULL;
}






int main()
{
    printf("main pthread start\n");
    pthread_t pthid1=0,pthid2 = 0;
    pthread_create(&pthid1,NULL,threadFunc1,NULL);
    pthread_create(&pthid2,NULL,threadFunc2,NULL);
    printf("main pthread %u, 子线程 %u %u\n",(unsigned int)pthread_self(),(unsigned int)pthid1,(unsigned int)pthid2);
    int cnt = 10;
    while(cnt--)
    {
        printf("main thread %u\n",(unsigned int)pthread_self() );
        //sleep(1);
    }
    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    printf("main pthread end\n");
    return 0;
}

