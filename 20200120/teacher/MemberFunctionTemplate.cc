///
/// @file    MemberFunctionTemplate.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-20 11:28:20
///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class CharArray {
	//typedef char * iterator;
	//typedef class CharIterator iterator;
public:
	using iterator = char *;

	CharArray(size_t capacity)
	: _capacity(capacity)
	, _buff(new char[_capacity]())
	{	cout << "CharArray(size_t)" << endl;	}

	CharArray(const char * pstr)
	: _capacity(strlen(pstr) + 1)
	, _buff(new char[_capacity]())
	{
		cout << "CharArray(const char*)" << endl;
		strcpy(_buff, pstr);
	}

	size_t size() const {	return strlen(_buff);	}

	iterator begin() {	return _buff;	}
	iterator end() {	return _buff + size(); }

	//普通类内部定义一个成员函数模板
	template <class Iterator>
	void printElements(Iterator beg, Iterator end)
	{
		while(beg != end) {
			cout << *beg << '\n';
			++beg;
		}
	}

	~CharArray() 
	{
		delete [] _buff;
		cout << "~CharArray()" << endl;
	}

	const char * c_str() const
	{	return _buff;	}

private:
	size_t _capacity;
	char * _buff;
};

int main(void)
{
	//vector<int>::iterator it;
	CharArray ca("hello,world");
	CharArray::iterator it;

	ca.printElements(ca.begin(), ca.end());

	return 0;
}
