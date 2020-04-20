 ///
 /// @file    deleter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-17 16:39:07
 ///
 
#include <stdio.h>

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;

//智能指针需要自定义删除器,回收资源

struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp) {
			fclose(fp);
			cout << ">> fclose(fp)" << endl;
		}
	}
};

void test0()
{
	//<> 代表的是模板参数列表
	unique_ptr<FILE, Fpcloser> up(fopen("hello.txt", "a+"), Fpcloser());
	string msg = "this is a new line\n";
	fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test1()
{
	shared_ptr<FILE> sp(fopen("hello.txt", "a+"), Fpcloser());
	string msg = "this is a new line\n";
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
