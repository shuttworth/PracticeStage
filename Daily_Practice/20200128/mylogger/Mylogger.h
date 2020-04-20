 ///
 /// @file    Mylogger.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 11:03:49
 ///
 
#ifndef __MYLOGGER_H__
#define __MYLOGGER_H__

#include <log4cpp/Category.hh>

using namespace log4cpp;

class Mylogger
{
public:
	static Mylogger * getInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Mylogger();

		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance) {
			delete _pInstance;
			_pInstance = nullptr;
		}
	}

	void warn(const char * msg);
	void error(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);

private:
	Mylogger();
	~Mylogger();

private:
	static Mylogger * _pInstance;
	//对象的数据成员
	Category & _mycat;
};

#define prefix(msg) string("[").append(__FILE__)\
			.append(":").append(__func__)\
			.append(":").append(std::to_string(__LINE__))\
			.append("] ").append(msg).c_str()


#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg));
#define LogError(msg) Mylogger::getInstance()->error(prefix(msg));
#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg));
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg));

#endif
