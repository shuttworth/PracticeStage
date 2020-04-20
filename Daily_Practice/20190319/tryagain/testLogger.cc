#include "Mylogger.h"
#include <string>
#include <iostream>


using std::cout;
using std::endl;
using std::string;


void test3()
{
    LogWarn("this is warn msg");
    LogInfo("this is info msg");
    LogError("this is error msg");
    LogDebug("this is debug msg");
}


int main()
{
    test3();
    return 0;
}

