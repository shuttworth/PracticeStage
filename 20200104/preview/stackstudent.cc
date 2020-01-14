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
public:
    student(int id,const char * name)
        :_id(id)
         ,_name(new char[strlen(name)+1]())
    {
        strcpy(_name,name);
        cout<<"student(int,char*)"<<endl;
    }

    ~student()
    {
        delete  [] _name;
        cout <<"~student()"<<endl;
    }

    void print()
    {
        cout<<"id=="<<_id
            <<", name=="<<_name<<endl;
    }

private:
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


};

int main(void)
{
    //目标是只有栈不用堆
    student stu1(100,"jay");
    stu1.print();

   // student *pstu =new student(101,"jj");//error
   // pstu->print();
   // delete pstu;

    return 0;
}
