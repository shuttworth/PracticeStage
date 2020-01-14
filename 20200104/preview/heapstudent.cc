#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class student
{
private:
    int _id;
    char * _name;
private:

    ~student()
    {
        delete  [] _name;
        cout <<"~student()"<<endl;
    }

public:
    student(int id,const char * name)
        :_id(id)
         ,_name(new char[strlen(name)+1]())
    {
        strcpy(_name,name);
        cout<<"student(int,char*)"<<endl;
    }


    void print()
    {
        cout<<"id=="<<_id
            <<" ,name=="<<_name<<endl;
    }

    void * operator new(size_t size)
    {
        cout<<"void * operator new(int size)"<<endl;
        void * ret=malloc(size);
        return ret;
    }

    void operator delete(void * ret)
    {
        free(ret);
        cout<<"void operator delete(void * ret)"<<endl;
    }

    void destroy()
    {
        delete this;
        cout <<"destroy()"<<endl;
    }

};

int main(void)
{
    //目标是只有堆栈类可以创建，栈不可以
   // student stu1(100,"jay");//error,通过破坏析构函数实现
   // stu1.print();

    student *pstu =new student(101,"jj");
    pstu->print();
   // delete pstu;

    pstu->destroy();
    return 0;
}
