#include <iostream>
    
#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>


using std::cout;
using std::endl;

using namespace log4cpp;

void test()
{
    OstreamAppender * Appender=new OstreamAppender("MY OstreamAppender",&cout);
    Appender->setLayout(new BasicLayout());
    

    Category & root = Category ::getRoot();
    root.setPriority(Priority::DEBUG);
    root.setAppender(Appender);

    root.emerg("this is a emerg message");
    root.fatal("this is a fatal message");
    root.alert("this is a alert message");
    root.crit("this is a crit message");

    Category::shutdown();
}
/*         1. 创建一个Appender，并指定其包含的Layout； */
/* 　　　　2. 从系统中得到Category的根，将Appender添加到该Category中； */
/* 　　　　3. 设置Category的优先级； */
/* 　　　　4. 记录日志； */
/* 　　　　5. 关闭Category。 */


int main()
{
    test();
    return 0;
}

