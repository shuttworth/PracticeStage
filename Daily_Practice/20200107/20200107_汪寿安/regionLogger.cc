#include <iomanip>
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


/* 封装log4cpp,使用起来比较方便，如下所示。 */

/*输出的日志信息能同时输出到终端和文件 */ 
//OstreamAppender FileAppender RollingFileAppender   

/* 加分项：输出的日志信息中最好能有文件的名字，函数的名字及其所在的行号 */
//使用单例模式

class Mylogger
{
public:
    void warn(const char * msg);
    void error(const char * msg);
    void debug(const char * msg);
    void info(const char * msg);

    static Mylogger * getInstance()
    {
        if(_pstr==nullptr)
        {
            _pstr = new Mylogger();
            //cout<<"static Mylogger * getInstance()"<<endl;
        }
        return _pstr;
    }

    static void destroy()
    {
        if(_pstr!=nullptr)
        {
            _pstr=nullptr;
        }
    }

private:
    Mylogger(){}
    ~Mylogger(){
        if(_pstr){
            delete  this;
        }
    }
private:
    static Mylogger * _pstr;
    //......
};

Mylogger * Mylogger::_pstr = nullptr;

void Mylogger::warn(const char * msg)
{
    PatternLayout * ptLayout1 = new PatternLayout();
    ptLayout1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout2 = new PatternLayout();
    ptLayout2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout3 = new PatternLayout();
    ptLayout3->setConversionPattern("%d %c [%p] %m%n");



    //文件，可以一直写
    FileAppender * fileAppender =
        new FileAppender("fileAppender", "wd.log");
    fileAppender->setLayout(ptLayout1);

    //回卷文件
    RollingFileAppender * rollAppender = new RollingFileAppender(
                                                                 "rollAppender",
                                                                 "rollwd.log",
                                                                 1024 * 5,
                                                                 3);
    rollAppender->setLayout(ptLayout2);

    //输出流
    OstreamAppender * osAppender = new OstreamAppender("osAppender",&cout);
    osAppender->setLayout(ptLayout3);

    //
    Category & root = Category::getRoot().getInstance("mycat");
    root.setPriority(Priority::WARN);//设置的是Category的优先级
    root.addAppender(fileAppender);
    root.addAppender(rollAppender);
    root.addAppender(osAppender);


    string msgnow = msg;
    msgnow=msgnow+"  "+(string)__FILE__+"  "+(string)__FUNCTION__+"  ";//+to_string((__LINE__))
    root.warn(msgnow+to_string((__LINE__)));
    root.error(msgnow+to_string((__LINE__)));

    Category::shutdown();
}

void Mylogger::info(const char * msg)
{
    PatternLayout * ptLayout1 = new PatternLayout();
    ptLayout1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout2 = new PatternLayout();
    ptLayout2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout3 = new PatternLayout();
    ptLayout3->setConversionPattern("%d %c [%p] %m%n");



    //文件，可以一直写
    FileAppender * fileAppender =
        new FileAppender("fileAppender", "wd.log");
    fileAppender->setLayout(ptLayout1);

    //回卷文件
    RollingFileAppender * rollAppender = new RollingFileAppender(
                                                                 "rollAppender",
                                                                 "rollwd.log",
                                                                 1024 * 5,
                                                                 3);
    rollAppender->setLayout(ptLayout2);

    //输出流
    OstreamAppender * osAppender = new OstreamAppender("osAppender",&cout);
    osAppender->setLayout(ptLayout3);

    //
    Category & root = Category::getRoot().getInstance("mycat");
    root.setPriority(Priority::INFO);//设置的是Category的优先级
    root.addAppender(fileAppender);
    root.addAppender(rollAppender);
    root.addAppender(osAppender);


    string msgnow = msg;
    msgnow=msgnow+"  "+(string)__FILE__+"  "+(string)__FUNCTION__+"  ";//+to_string((__LINE__))
    root.warn(msgnow+to_string((__LINE__)));
    root.error(msgnow+to_string((__LINE__)));
    Category::shutdown();
}

void Mylogger::error(const char * msg)
{
    PatternLayout * ptLayout1 = new PatternLayout();
    ptLayout1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout2 = new PatternLayout();
    ptLayout2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout3 = new PatternLayout();
    ptLayout3->setConversionPattern("%d %c [%p] %m%n");



    //文件，可以一直写
    FileAppender * fileAppender =
        new FileAppender("fileAppender", "wd.log");
    fileAppender->setLayout(ptLayout1);

    //回卷文件
    RollingFileAppender * rollAppender = new RollingFileAppender(
                                                                 "rollAppender",
                                                                 "rollwd.log",
                                                                 1024 * 5,
                                                                 3);
    rollAppender->setLayout(ptLayout2);

    //输出流
    OstreamAppender * osAppender = new OstreamAppender("osAppender",&cout);
    osAppender->setLayout(ptLayout3);

    //
    Category & root = Category::getRoot().getInstance("mycat");
    root.setPriority(Priority::ERROR);//设置的是Category的优先级
    root.addAppender(fileAppender);
    root.addAppender(rollAppender);
    root.addAppender(osAppender);


    string msgnow = msg;
    msgnow=msgnow+"  "+(string)__FILE__+"  "+(string)__FUNCTION__+"  ";//+to_string((__LINE__))
    root.warn(msgnow+to_string((__LINE__)));
    root.error(msgnow+to_string((__LINE__)));
    Category::shutdown();
}

void Mylogger::debug(const char * msg)
{
    PatternLayout * ptLayout1 = new PatternLayout();
    ptLayout1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout2 = new PatternLayout();
    ptLayout2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptLayout3 = new PatternLayout();
    ptLayout3->setConversionPattern("%d %c [%p] %m%n");



    //文件，可以一直写
    FileAppender * fileAppender =
        new FileAppender("fileAppender", "wd.log");
    fileAppender->setLayout(ptLayout1);

    //回卷文件
    RollingFileAppender * rollAppender = new RollingFileAppender(
                                                                 "rollAppender",
                                                                 "rollwd.log",
                                                                 1024 * 5,
                                                                 3);
    rollAppender->setLayout(ptLayout2);

    //输出流
    OstreamAppender * osAppender = new OstreamAppender("osAppender",&cout);
    osAppender->setLayout(ptLayout3);

    //
    Category & root = Category::getRoot().getInstance("mycat");
    root.setPriority(Priority::DEBUG);//设置的是Category的优先级
    root.addAppender(fileAppender);
    root.addAppender(rollAppender);
    root.addAppender(osAppender);


    // oss << idx << "th: a new message helo,world hello wangda";
    string msgnow = msg;
    msgnow=msgnow+"  "+(string)__FILE__+"  "+(string)__FUNCTION__+"  ";//+to_string((__LINE__))
    root.warn(msgnow+to_string((__LINE__)));
    root.error(msgnow+to_string((__LINE__)));
    Category::shutdown();
}






int main(void)
{

    Mylogger * log = Mylogger::getInstance();
    log->info("Message");   
    log->error("Message"); 
    log->warn("Message"); 
    log->debug("Message"); 
    log->destroy();
}

