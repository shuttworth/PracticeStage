#ifndef __WD_MYLOGGER_H__
#define __WD_MYLOGGER_H__

#include <string>
#include <log4cpp/Category.hh>
using namespace log4cpp;
using std::string;


class Mylogger
{
public:
    static Mylogger * getInstance();
    static void shutdown();

    void info(const char *msg);
    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);

private:
    Mylogger();
    ~Mylogger();

    static Mylogger * _pInstance;//在外面初始化
    Category & _root;

};


#define prefix(msg) string().append(__FILE__)\
    .append("-").append(__FUNCTION__)\
    .append("-").append(std::to_string(__LINE__))\
    .append(msg).c_str()


#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define LogError(msg) Mylogger::getInstance()->error(prefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg))



#endif
