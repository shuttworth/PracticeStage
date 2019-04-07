//通过可变参数，实现日志信息的记录
#ifndef __WD_MYLOGGER_H__
#define __WD_MYLOGGER_H__

#include <log4cpp/Category.hh>
#include <string>
using std::string;
using namespace log4cpp;

class Mylogger
{
public:
	static Mylogger * getInstance();
	static void shutdown();

	void info(const char * msg); 
	template <typename... Args>
	void info(const char * msg, Args... args)
	{
		_root.info(msg, args...);
	}

	void warn(const char * msg);
	template <typename... Args>
	void warn(const char * msg, Args... args)
	{
		_root.warn(msg, args...);
	}

	void error(const char * msg);
	template <typename... Args>
	void error(const char * msg, Args... args)
	{
		_root.error(msg, args...);
	}

	void debug(const char * msg);
	template <typename... Args>
	void debug(const char * msg, Args... args)
	{
		_root.debug(msg, args...);
	}

private:
	Mylogger();
	~Mylogger();
	
private:
	Category & _root;
	static Mylogger * _pInstance;
};

#define prefix(msg) string().append("[").append(__FILE__)\
	.append("-").append(__FUNCTION__)\
	.append("-").append(std::to_string(__LINE__))\
	.append("] ").append(msg).c_str()

#define LogWarn(msg, ...) Mylogger::getInstance()->warn(prefix(msg), ##__VA_ARGS__)  //如果可变参数被忽略或为空，’##’操作将使预处理器去除掉它前面的那个逗号。
#define LogInfo(msg, ...) Mylogger::getInstance()->info(prefix(msg), ##__VA_ARGS__)
#define LogError(msg, ...) Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__)
#define LogDebug(msg, ...) Mylogger::getInstance()->debug(prefix(msg), ##__VA_ARGS__)

#endif
