#include "Mylogger.h"
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

Mylogger * Mylogger::_pInstance=NULL; //在这儿赋初值不会重定义

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
    {
        delete _pInstance;
    }
}




Mylogger::Mylogger()
    :_root(Category::getRoot().getInstance("mycat")) //关于这一段的具体写法，需要听视频再看一看
{
    PatternLayout * ptn1=new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptn2=new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    OstreamAppender * pOstreamApp=new OstreamAppender("pOstreamApp",&cout);
    pOstreamApp->setLayout(ptn1);

    FileAppender * pfileApp=new FileAppender("fileApp","wd.log");
    pfileApp->setAppend(ptn2);

    _root.setAppender(pOstreamApp);
    _root.setAppender(pfileApp);
    _root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    Category::shutdown();
}


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
