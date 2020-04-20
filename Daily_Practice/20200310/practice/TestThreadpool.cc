#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>

using namespace wd;
using namespace std;


class MyTask
:public Task
{
    public:
        void process()
        {
            ::srand(::time(NULL));
            int number = rand() % 100;
            cout<<" pthid= "<<pthread_self()<<",number= "<<number<<endl;
        }
};

void test0()
{
    //改了Task为Mytask
    unique_ptr<MyTask> up(new MyTask());
    unique_ptr<Threadpool>ThreadpoolPtr(new Threadpool(5,10));
    ThreadpoolPtr->start();
    int cnt=30;
    while(cnt--)
    {
        ThreadpoolPtr->addTask(up.get());
    }

    cout<<">> test(): exit while(cnt--)  " << endl;
    ThreadpoolPtr->stop();

}


int main()
{
    test0();
    return 0;
}

