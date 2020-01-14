#include <string.h>
#include <iostream>

using namespace std;


class student
{
public:
    student(const char * name,int id)
    :_id(id)
    ,_name(new char[strlen(name)+1]())
    {
        cout<<"student(const char * ,int )"<<endl;
        strcpy(_name,name);
    }

    
    void * operator new(size_t size)
    {
        cout<<"void * operator new(size_t size)"<<endl;
        int * p = (int *)malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        free(p);
        cout<<"void operator delete(void *p)"<<endl;
    }


    void print()
    {
        cout<<"name:"<<_name<<endl;
        cout<<"id:"<<_id<<endl;
    }

    void destroy()
    {
        delete this;
    }
private:
    int _id;
    char * _name;
    ~student(){ //放到私有区的成员函数不需要再写实现
        cout<<"~student()"<<endl;

    }
};

int main()
{
    //student s1("ming",21);
   // s1.print();
    
    student * s2=new student("uzi",22); //目标只用堆不用栈
    s2->print();
    
    s2->destroy();
    //delete s2; error
    return 0;
}

