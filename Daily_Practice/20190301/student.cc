#include <string.h>
//#include <stdlib.h>
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
        cout<<"student(int id,char * name)"<<endl;
    }

    ~student()
    {
        delete [] _name;
        cout <<"~student"<<endl;
    }

    void print()
    {
        cout<<"_Id=="<<_id<<endl
             <<"_name=="<<_name<<endl;
    }

    void *operator new(size_t size)
    {
        cout<<"void *operator new(size_t size)"<<endl;
        void * ret=malloc(size);
        return ret;

    }

    void operator delete(void * ret)
    {
        free(ret);
        cout<<" void operator delete(void * ret)"<<endl;
    }
};

int main(void)
{
    student stu1(100,"jay");
    stu1.print();

    student *pstu =new student(101,"jj");//new后面不光可以写成new char，还可以写成new student ，其实就是new给一个东西分配空间
    pstu->print();
    delete(pstu);
    return 0;


}
