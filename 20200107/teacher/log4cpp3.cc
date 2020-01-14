 
#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>


using std::cout;
using std::endl;

using namespace log4cpp;

void test0()
{
	PatternLayout * ptLayout1 = new PatternLayout();  //PatternLayout()
	ptLayout1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * ptLayout2 = new PatternLayout();
	ptLayout2->setConversionPattern("%d %c [%p] %m%n");

	OstreamAppender * osAppender = new 
		OstreamAppender("osAppender", &cout);
	osAppender->setLayout(ptLayout1);

	FileAppender * fileAppender = 
		new FileAppender("fileAppender", "wd.log");
	fileAppender->setLayout(ptLayout2);

	//
	Category & root = Category::getRoot().getInstance("mycat"); //这里给category一个新名字,不设置就没有
	//Category & root = Category::getRoot(); 
	root.setPriority(Priority::ERROR);//设置的是Category的优先级
	root.setAppender(osAppender);
	root.addAppender(fileAppender);

	root.emerg("this is an emerg message");
	root.fatal("this is a fatal message.");
	root.alert("this is an alert message.");
	root.crit("this is a crit message.");
	root.error("this is an error message.");
	root.warn("this is a warn message.");
	root.notice("this is a notice message.");
	root.info("this is an info message.");
	root.debug("this is a debug message.");


	//Category::shutdown();
    root.shutdown();
}
 
int main(void)
{
	test0();
	return 0;
}
