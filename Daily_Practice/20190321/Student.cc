#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name, name);
		cout << "String(int, const char*)" << endl;
	}

	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}

	void print() const
	{
		cout << "id:" << _id << endl
			 << "name: " << _name << endl;
	}
# if 0
	//是我们重载的
	void * operator new(size_t size)
	{//zmalloc
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(size);//自定义开辟空间的方式
		return ret;
	}

	void operator delete(void * ret)
	{
		cout << "void operator delete(void*)" << endl;
		free(ret);
	}
#endif
private:
	int _id;
	char * _name;
};
 


	void * operator new(size_t size)
	{//zmalloc
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(size);//自定义开辟空间的方式
		return ret;
	}

	void operator delete(void * ret)
	{
		cout << "void operator delete(void*)" << endl;
		free(ret);
	}
//把new和delete放在外面，则所有类型的new都会经过这个重载的new，因此这个new执行了两次

int main(void)
{
	Student * pstu = new Student(100, "Jackie");
	pstu->print();

	delete pstu;

//	Student stu1(101, "Marry");
//	stu1.print();
	return 0;
}
