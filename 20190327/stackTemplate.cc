//用模板的形式实现stack栈

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T, int kSize = 10>
class Stack
{
public:
	Stack()
	: _top(-1)
	, _array(new T[kSize]())
	{}

	~Stack()
	{
		delete [] _array;
	}

	bool empty() const;
	bool full() const;
	void push(const T & t);
	void pop();
	T top();

private:
	int _top;
	T * _array;
};

template <typename T, int kSize> //在类之外定义，每次写之前都要加上这一行的内容
bool Stack<T, kSize>::empty() const
{
	return _top == -1;
}


template <typename T, int kSize>
bool Stack<T, kSize>::full() const
{
	return _top == kSize - 1;
}

template <typename T, int kSize>
void Stack<T, kSize>::push(const T & t)
{
	if(!full()) {
		_array[++_top] = t;
	} else
		cout << "stack is full, cannot push data any more!" << endl;
}

template <typename T, int kSize>
void Stack<T, kSize>::pop()
{
	if(!empty())
		--_top;
	else 
		cout << "stack is empty, no more data!" << endl;
}

template <typename T, int kSize>
T Stack<T, kSize>::top() {
	return _array[_top];
}
 
int test0(void)
{
	Stack<int> stack; //vector其实就是类模板
	cout << "此时栈中是否为空？" << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈中是否为空？" << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		stack.push(idx);
	}

	cout << "此时栈中是否已满？" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	return 0;
}
int test1(void)
{
	Stack<string> stack;
	cout << "此时栈中是否为空？" << stack.empty() << endl;
	stack.push("aaa");
	cout << "此时栈中是否为空？" << stack.empty() << endl;

	for(int idx = 1; idx != 11; ++idx)
	{
		stack.push(string(3, 'a' + idx));
	}

	cout << "此时栈中是否已满？" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	return 0;
}

int main(void)
{
	test1();
	return 0;
}
