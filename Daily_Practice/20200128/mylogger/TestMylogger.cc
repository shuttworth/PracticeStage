 ///
 /// @file    TestMylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 11:30:58
 ///
 
#include "Mylogger.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;


void test0()
{
	Mylogger::getInstance()->warn("hello,warn, %d");
	Mylogger::getInstance()->error("hello,error");
	Mylogger::getInstance()->info("hello,info");
	Mylogger::getInstance()->debug("hello,debug");


	Mylogger::destroy();
}

void test2()
{
	Mylogger::getInstance()->warn(prefix("hello,warn"));
	Mylogger::getInstance()->error(prefix("hello,error"));
	Mylogger::getInstance()->info(prefix("hello,info"));
	Mylogger::getInstance()->debug(prefix("hello,debug"));

	Mylogger::destroy();
}

void test3()
{
	//仅仅只能记录字符串
	LogWarn("hello,warn");
	LogError("hello,error");
	LogInfo("hello,ifno");
	LogDebug("hello,debug");
}

void test4()
{
	int number = 1;
	LogWarn("hello, %d", nubmer);//error
}

void test1()
{
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __func__ << endl;
	cout << __FUNCTION__ << endl;
}
 
int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
