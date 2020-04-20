#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	CharArray(int size)
	: _size(size)
	, _pdata(new char[_size]()) {
	
	}

	//二元运算符，对[]运算符重载
	char & operator[](int idx)
	{
		cout << "char & operator[](int)" << endl;
		static char nullchar = '\0';
		if(idx < 0 || idx >= _size) {
			cout << "idx 越界" << endl;
			return nullchar;
		} else {
			return _pdata[idx];
		}
	}
	
private:
	int _size;
	char * _pdata;
};
 
int main(void)
{
	const char * pstr = "hello,world";
	int len = strlen(pstr) + 1;
	CharArray ca(len);
	
	for(int idx = 0; idx != len; ++idx) {
		ca[idx] = pstr[idx];
	}

	for(int idx = 0; idx != len; ++idx) {
		cout << ca[idx];
	}
	cout << endl;

	return 0;
}
