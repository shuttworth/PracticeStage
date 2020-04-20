#include "Mylogger.h"
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

Mylogger * Mylogger::_pInstance = NULL;

Mylogger * Mylogger::getInstance()
{
	if(_pInstance == NULL) {
		_pInstance = new Mylogger();
	}
	return _pInstance;
}

void Mylogger::shutdown() 
{
	if(_pInstance)
		delete _pInstance;
}

Mylogger::Mylogger()
: _root(Category::getRoot().getInstance("myCat"))
{
	PatternLayout * ptn1 = new PatternLayout();
	ptn1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * ptn2 = new PatternLayout();
	ptn2->setConversionPattern("%d %c [%p] %m%n");

	OstreamAppender * pOstreamApp = new OstreamAppender("pOstreamAPP", &cout);
	pOstreamApp->setLayout(ptn1);

	FileAppender * pFileApp = new FileAppender("pFileApp", "wd.log");
	pFileApp->setLayout(ptn2);

	_root.setAppender(pOstreamApp);
	_root.setAppender(pFileApp);
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
