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

    ~student(){
        cout<<"~student()"<<endl;

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

    void * operator new(size_t size)
    {
        cout<<"void * operator new(size_t size)"<<endl;
        int * p = (int *)malloc(size);
        return p;
    }
};

int main()
{
    student s1("ming",21); //目标只用栈不用堆
    s1.print();
    
   // student * s2=new student("uzi",22);
   // s2->print();                          //error

   // delete s2;
    return 0;
}

