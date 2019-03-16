#include<string.h>
#include<stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class student
{
public:
    student(int id,const char* name)//const记住，这里得写上
        :_id(id)
         ,_name(new char[strlen(name)+1]())
    {
        strcpy(_name,name);
        cout<<"student(int id,char* name)"<<endl;
    }

    ~student()
    {
        delete [] _name;
        cout <<"~student()"<<endl;
    }


    void print()
    {
        cout<<"_id=="<<_id<<endl;
        cout<<"_name=="<<_name<<endl;

    }
private:
    void * operator new(size_t size)
    {
        void * ret=malloc(size);
        return  ret;
        cout <<"void * operator new(size_t size)"<<endl;
    }

    void operator delete(void* ret)
    {
        free(ret);
        cout<<"void operator delete()"<<endl;
    }
private:
    int _id;
    char* _name;
};

int main(void)
{
    student stu1(100,"jaychou");
    stu1.print();
//目标是只用栈,不用堆
//
   // student *pstu=new student(200,"jj");//error
   // pstu->print();
   // delete pstu;
    return 0;
}
