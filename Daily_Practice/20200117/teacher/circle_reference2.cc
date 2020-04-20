 ///
 /// @file    circle_reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-17 14:32:34
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Parent;

class Child
{
public:
	Child()
	: _parentPtr()
	{	cout << "Child()" << endl;	}
	~Child() {	cout << "~Child()" << endl;	}

	void print() const {	cout << "Child::print()" << endl;	}

	shared_ptr<Parent> _parentPtr;
	long _x11;
	long _x12;
	long _x13;
};


class Parent
{
public:
	Parent() {	cout << "Parent()" << endl;	}

	~Parent() {	cout << "~Parent()" << endl;	}

	void print() const {	cout << "Parent::print()" << endl;	}

	weak_ptr<Child> _childPtr;
	long _x21;
	long _x22;
	long _x23;
};
 
//weak_ptr与shared_ptr联合使用，可以解决
//shared_ptr循环引用导致内存泄漏的问题
int main(void)
{

	//shared_ptr的内部有2个成员
	//1个指向资源，另一个指向引用计数
	shared_ptr<Child> childPtr(new Child());
	shared_ptr<Parent> parentPtr(new Parent());

	//shared_ptr = shared_ptr
	childPtr->_parentPtr = parentPtr;
	//weak_ptr 在执行赋值或者复制, 并不会导致引用计数加1, 引用计数不变
	//当一个资源交给weak_ptr进行托管之后，
	//它知道托管的资源是否还存活
	//
	//weak_ptr = shared_ptr;
	parentPtr->_childPtr = childPtr;

	cout << "parentPtr's use_count:" << parentPtr.use_count() << endl;
	cout << "childPtr's use_count:" << childPtr.use_count() << endl;

	cout << "sizeof(cout): " << sizeof(cout) << endl;
	cout << "sizeof(cin): " << sizeof(std::cin) << endl;
	cout << "sizeof(childPtr): " << sizeof(childPtr) << endl;
	cout << "sizeof(parentPtr): " << sizeof(parentPtr) << endl;


	return 0;
}
