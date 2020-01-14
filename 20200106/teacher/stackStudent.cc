 ///
 /// @file    Student.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 09:56:00
 ///
 

//#include "myhead.h"  //  自定义头文件放在C头文件的上面

#include <string.h>   //C的头文件要放在C++头文件的上面

#include <iostream>

//第三方库头文件
using std::cout;
using std::endl;

class Student
{
public:
	Student(const char * name, int id)
	: _name(new char[strlen(name) + 1]())
	, _id(id)
	{
		cout << "Student(const char*, int)" << endl;
		strcpy(_name, name);
	}

	void print() const
	{
		cout << "name:" << _name << endl
			 << "id: " << _id << endl;
	}

	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}

	//sz的大小不需要主动传递，系统会自动完成
	//
	//只关心开辟空间，而该空间要放什么类型的数据
	//它是不关心的

private:
	//不需要调用，就不用实现
	void * operator new(size_t sz);
	void operator delete(void * p);

private:
	char * _name;
	int _id;
};
 
int main(void)
{
	Student stu("Rose", 101);//ok

	Student * pstu = new Student("Mike", 100);//error
	pstu->print();

	//delete pstu;
 
	return 0;
}
