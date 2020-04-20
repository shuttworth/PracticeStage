 ///
 /// @file    Mylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 11:18:44
 ///
 
#include "Mylogger.h"

#include <iostream>

#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;

Mylogger * Mylogger::_pInstance = nullptr;

Mylogger::Mylogger()
: _mycat(Category::getRoot().getInstance("wd"))
{
	PatternLayout * ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d %c [%p] %m%n");

	OstreamAppender * osAppender = new OstreamAppender("os", &cout);
	osAppender->setLayout(ptnLayout1);

	FileAppender * fileAppender = new FileAppender("file", "wd.log");
	fileAppender->setLayout(ptnLayout2);
	
	_mycat.addAppender(osAppender);
	_mycat.addAppender(fileAppender);
	_mycat.setPriority(Priority::DEBUG);
	cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger()
{
	Category::shutdown();	
	cout << "~Mylogger()" << endl;
}

void Mylogger::warn(const char * msg)
{
	_mycat.warn(msg);
}

void Mylogger::error(const char * msg)
{
	_mycat.error(msg);
}

void Mylogger::info(const char * msg)
{
	_mycat.info(msg);
}

void Mylogger::debug(const char * msg)
{
	_mycat.debug(msg);
}
