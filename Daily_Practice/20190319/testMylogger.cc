#include "MyLogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;




void test0()
{
    Mylogger::getInstance()->warn("this is warn msg");
    Mylogger::getInstance()->info("this is info msg");
    Mylogger::getInstance()->error("this is error msg");
    Mylogger::getInstance()->debug("this is debug msg");
}

void test1()//实现加分项的要求,用系统内置的来实现打印文件名 函数名 行
{
    cout<<__FILE__<<endl;
    cout<<__FUNCTION__<<endl;
    cout<<__LINE__<<endl;
}

void test2()
{
    Mylogger::getInstance()->warn(prefix("  this is warn msg"));//把定义的宏放到头文件里
    Mylogger::getInstance()->info(prefix("  this is info msg"));
    Mylogger::getInstance()->error(prefix("  this is error msg"));
    Mylogger::getInstance()->debug(prefix("  this is debug msg"));
}

void test3()
{
    LogWarn("this is warn msg");  //通过宏定义来实现简洁编
    LogInfo("this is info msg");
    LogError("this is error msg");
    LogDebug("this is debug msg");

}


int main(void )
{
   // test0();
   //test1();
    //test2();
    test3();
}
