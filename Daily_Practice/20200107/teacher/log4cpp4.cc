 ///
 /// @file    log4cpp1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-07 16:57:44
 ///
 
#include <iostream>
#include <sstream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>


using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

using namespace log4cpp;

void test0()
{
	PatternLayout * ptLayout1 = new PatternLayout();
	ptLayout1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * ptLayout2 = new PatternLayout();
	ptLayout2->setConversionPattern("%d %c [%p] %m%n");

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

	//
	Category & root = Category::getRoot().getInstance("mycat");
	root.setPriority(Priority::DEBUG);//设置的是Category的优先级
	root.addAppender(fileAppender);
	root.addAppender(rollAppender);


	for(size_t idx = 0; idx != 100; ++idx) {
		ostringstream oss;
		oss << idx << "th: a new message helo,world hello wangdao";
		string msg = oss.str();
		root.warn(msg);
		root.error(msg);
	}

	Category::shutdown();
}
 
int main(void)
{
	test0();
	return 0;
}
