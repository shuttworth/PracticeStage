#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using namespace std;

int main(int argc, char* argv[])
{
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
    osAppender->setLayout(new log4cpp::BasicLayout());

    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.addAppender(osAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in a Error Message!");
    root.warn("Hello log4cpp in a Warning Message!");

    log4cpp::Category::shutdown();    
    return 0;
}

/*
 *1. 创建一个Appender，并指定其包含的Layout；
  　　　　2. 从系统中得到Category的根，将Appender添加到该Category中；
  　　　　3. 设置Category的优先级；
  　　　　4. 记录日志；
  　　　　5. 关闭Category。

  Category负责向日志中写入信息，
  Appender负责指定日志的目的地，
  Layout负责设定日志的格式，
  Priority被用来指定Category的优先级和日志的优先级，
  NDC则是一种用来区分不同场景中交替出现的日志的手段。
  */
