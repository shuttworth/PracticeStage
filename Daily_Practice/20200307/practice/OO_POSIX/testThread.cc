#include "thread.h"
#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread
:public wd::thread
{
public:
    ~MyThread() {   cout << "~MyThread() " << endl; }
private:
    void run() override //基类有虚函数run,派生类里覆盖override了run
    {
        int cnt = 10;
        ::srand(::clock());
        while(cnt--) {
            int number = ::rand() % 100;
            cout << "sub Thread " << pthread_self() 
                << ": getNumber = " << number << endl;
            ::sleep(1);
        }
    }

};


void test0()
{
    cout<<"main thread "<<pthread_self()<<endl;
    unique_ptr<wd::thread> mythread(new MyThread());
    mythread->start();
    mythread->join();
}



int main()
{
    test0();
    return 0;
}

