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

    void print()
    {
        cout<<"_id=="<<_id<<endl;
        cout<<"_name=="<<_name<<endl;

    }

    void destroy()
    {
        delete this;
    }

private:
    int _id;
    char* _name;


    ~student()
    {
        delete [] _name;
        cout <<"~student()"<<endl;
    }
};

int main(void)
{
    //要求只用堆不用栈
    // student stu1(100,"jaychou");//error
    // stu1.print();

    student *pstu=new student(200,"jj");
    pstu->print();
    // delete pstu;
    pstu->destroy();
    return 0;
}
