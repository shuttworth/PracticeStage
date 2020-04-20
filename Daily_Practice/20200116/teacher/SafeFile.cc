 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-16 17:41:05
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
	//当对象创建时，托管资源
	SafeFile(FILE * fp)
	: _fp(fp)
	{
		if(_fp == nullptr) {
			std::cerr << "_fp is nullptr\n";
		}
	}

	//提供若干访问资源的方法
	void write(const string & name)
	{
		fwrite(name.c_str(), 1, name.size(), _fp);
	}

	~SafeFile()
	{
		//当对象销毁时，释放资源
		if(_fp) {
			fclose(_fp);
			cout << "fclose(_fp) " << endl;
		}
	}

private:
	FILE * _fp;
};
 
int main(void)
{
	//用对象的生命周期管理资源
	SafeFile sf(fopen("hello.txt", "a+"));
	string msg = "hello,world";
	sf.write(msg);

	return 0;
}
