#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;

class student
{
private:
    int _age;
    char * _name;
    public:
        student(int age,const char* name)
        :_age(age)
         ,_name(new char[strlen(name)+1]())
        {
            strcpy(_name,name);
            cout<<"student(int id,const char* name)"<<endl;
        }

        ~student()
        {
            delete [] _name;
            cout<<"~student()"<<endl;
        }

        void* operator new(size_t size) //重构的new和delete什么时候可以cout内容出来
        {
            void * ret=malloc(size);
            return ret;
            cout<<"void* operator new(size_t size)"<<endl;
    
        }

        void operator delete(void *ret)
        {
            free(ret);
            cout<<"void operator delete(void *)"<<endl;
        }

        void print()
        {
            cout<<_age <<" is age"
                <<","<<_name <<" is name"<<endl;
        }

        void destroy()
        {
            delete this;
        }
};


int main()
{
   // student st1(22,"日天");
   student * st1=new student(22,"日天");
    st1->print();
    st1->destroy();
    return 0;

}

