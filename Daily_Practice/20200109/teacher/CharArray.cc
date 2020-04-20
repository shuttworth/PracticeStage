 ///
 /// @file    CharArray.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 15:50:18
 ///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	explicit
	CharArray(int size = 10)
	: _size(size)
	, _pdata(new char[_size]())
	{
		
	}

	//下标访问运算符
	//	std::string 
	//	std::vector
	//	下标类型不一定是整型，可以是任意类型
	char & operator[](int idx)
	{
		cout << "char&operator[](int)" << endl;
		if(idx >=0 && idx < _size)
		{
			return _pdata[idx];
		} else {
			static char nullchar = '\0';
			return nullchar;
		}
	}

	~CharArray()
	{
		delete [] _pdata;
	}

	int size() const {	return _size;	}

private:
	int _size;
	char * _pdata;
};
 
int main(void)
{
	//int arr[5] = {1, 2, 3, 4, 5};
	//arr[1];//arr.operator[](1);
	
	const char * pstr = "hello,world";
	int length = strlen(pstr);
	CharArray array(length);
	for(int idx = 0; idx != length; ++idx) {
		array[idx] = pstr[idx];
	}

	for(int idx = 0; idx != array.size(); ++idx) {
		cout << array[idx];
	}
	cout << endl;
	return 0;
}
