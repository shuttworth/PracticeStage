#include <iostream>
#include <sstream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>

using namespace std;
using namespace log4cpp;


void test0()
{
    PatternLayout * pt1=new PatternLayout();
    pt1->setConversionPattern("%d %c [%p] %m%n");

    
    PatternLayout * pt2=new PatternLayout();
    pt2->setConversionPattern("%d %c [%p] %m%n");

    FileAppender * fileAppender = 
        new FileAppender("wade","wd.log");
    fileAppender->setLayout(pt1);

    RollingFileAppender * rollingFileAppender = 
        new RollingFileAppender(
            "rollAppender",
            "rollwd.log"
            ,1024*5,
            3);
    rollingFileAppender ->setLayout(pt2);


    Category & myCate = Category::getRoot().getInstance("jarvis");
    myCate.setPriority(Priority::DEBUG);
    myCate.addAppender(fileAppender);
    myCate.addAppender(rollingFileAppender);
     for(size_t idx = 0; idx != 100; ++idx) {
          ostringstream oss;
        oss << idx << "th: a new message helo,world hello wangda";
        string msg = oss.str();
        myCate.warn(msg);
        myCate.error(msg);
    }

    Category::shutdown();
}

int main(void)
{
    test0();
    return 0;
}




}


