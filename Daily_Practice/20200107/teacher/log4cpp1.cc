 ///
 /// @file    log4cpp1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-07 16:57:44
 ///
 
#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>


using std::cout;
using std::endl;

using namespace log4cpp;

void test0()
{
	OstreamAppender * osAppender = new 
		OstreamAppender("lll", &cout);
	osAppender->setLayout(new BasicLayout());

	//
	Category & root = Category::getRoot();
	root.setPriority(Priority::ERROR);//设置的是Category的优先级
	root.setAppender(osAppender);

	root.emerg("this is an emerg message");
	root.fatal("this is a fatal message.");
	root.alert("this is an alert message.");
	root.crit("this is a crit message.");
	root.error("this is an error message.");
	root.warn("this is a warn message.");
	root.notice("this is a notice message.");
	root.info("this is an info message.");
	root.debug("this is a debug message.");


	Category::shutdown();
}
 
int main(void)
{
	test0();
	return 0;
}