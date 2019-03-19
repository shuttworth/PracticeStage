#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <iostream>

using std::cout;
using std::endl;
using namespace log4cpp;


int main(void )
{
    PatternLayout * ptn1=new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptn2=new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");
    
    OstreamAppender * pOstreamApp=new OstreamAppender("pOstreamApp",&cout);
    pOstreamApp->setLayout(ptn1);

    FileAppender * fileApp=new FileAppender("fileApp","wd.log");
    fileApp->setAppend(ptn2);
    
   // Category 用引用的方式返回
    Category & root=Category::getRoot();
    root.addAppender(pOstreamApp);//日志格式的初始化
    root.addAppender(fileApp);
    root.setPriority(Priority::WARN);//这里设置的是Category对象的级别
    

    //当日志的级别大于等于Category的级别时，日志会记录下来；否则会被忽略掉
    root.debug("this is debug message");//debug代表的是日志的级别
    root.info("this is debug message");
    root.notice("this is notice message");
    root.warn("this is warn message");
    root.error("this is error message");
    root.crit("this is crit message");
    root.alert("this is alert message");

    Category::shutdown();


    return 0;
}
