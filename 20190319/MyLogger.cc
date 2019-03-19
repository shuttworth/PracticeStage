#include "MyLogger.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

Mylogger * Mylogger::_pInstance=NULL;//直接放到这儿就不会重定义

Mylogger * Mylogger::getInstance()
{
    if(_pInstance==NULL)
    {
        _pInstance=new Mylogger();
    }
    return _pInstance;
}

void Mylogger::shutdown()
{
    if(_pInstance)
        delete _pInstance;
}



Mylogger::Mylogger()//单例协议，私有的，需要通过class类名来访问
    :_root(Category::getRoot().getInstance("mycat"))
{

    PatternLayout * ptn1=new PatternLayout();//layout设置日志的格式
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptn2=new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    OstreamAppender * pOstreamApp=new OstreamAppender("pOstreamApp",&cout);//setAppender 用来指定日志的目的地
    pOstreamApp->setLayout(ptn1);

    FileAppender * pfileApp=new FileAppender("fileApp","wd.log");
    pfileApp->setAppend(ptn2);

    _root.setAppender(pOstreamApp);
    _root.setAppender(pfileApp);


}


Mylogger::~Mylogger()
{
    Category::shutdown();
}

//_root 是category类型的，用来向日志里写入信息
void Mylogger::info(const char * msg)
{
    _root.info(msg);
}
void Mylogger::warn(const char * msg)
{
    _root.warn(msg);
}
void Mylogger::error(const char * msg)
{
    _root.error(msg);
}
void Mylogger::debug(const char * msg)
{
    _root.debug(msg);
}



