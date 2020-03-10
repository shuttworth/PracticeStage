///
/// @file    ClassTemplate.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-20 11:55:26
///

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//	   实例化
//类模板 ==》 模板类

template <class T, int kMax = 10>
class Stack{

	//template <class T3>
	//class StackImpl;

public:
	Stack()
	: _top(-1)
	, _base(new T[kMax]())
	{}

	//template <class T2>
	//void func(T2 )
	//{};

	bool empty() const;
	bool full() const;
	void push(T t);
	void pop();
	T top();

	~Stack() {	
		if(_base) {
			delete [] _base;
		}
	}
private:
	int _top;
	T * _base;
};

template <class T, int kMax>
bool Stack<T, kMax>::empty() const 
{	return  _top == -1;   }

template <class T, int kMax>
bool Stack<T, kMax>::full() const 
{	return _top == kMax - 1;	}

template <class T, int kMax>
void Stack<T, kMax>::push(T t) {
	if(!full()) {
		_base[++_top] = t;
	} else {
		std::cerr << "stack is full, cannot push any more data!\n";
	}
}

template <class T, int kMax>
void Stack<T, kMax>::pop() {
	if(!empty()) {
		--_top;
	} else {
		std::cerr << "stack is empty, no more data!\n";
	}
}

template <class T, int kMax>
T Stack<T, kMax>::top() {
	return _base[_top];
}

int test0(void)
{
	Stack<int> stack;
	cout << "stack is empty?" << stack.empty() << endl;
	stack.push(1);
	cout << "stack is empty?" << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		stack.push(idx);
	}
	cout << "stack is full ?" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}

int test1(void)
{
	//vector<int> numbers;

	Stack<string> stack;

	cout << "stack is empty?" << stack.empty() << endl;
	stack.push("aaa");
	cout << "stack is empty?" << stack.empty() << endl;

	for(int idx = 1; idx != 11; ++idx) {
		stack.push(string(3, 'a' + idx));
	}
	cout << "stack is full ?" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}

int main(void)
{
	test1();
	return 0;
}
