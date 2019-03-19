#ifndef __WD_MYLOGGER_H__
#define __WD_MYLOGGER_H__

#include <log4cpp/Category.hh>
using namespace log4cpp;

class Mylogger
{
    public:
        static Mylogger * getInstance();
        static void shutdown();

        void info(const char * msg);
        void warn(const char * msg);
        void error(const char * msg);
        void debug(const char * msg);

    private:
        Mylogger();
        ~Mylogger();

        static Mylogger * _pInstance; //私有的静态指针没有定义，需要在外部定义
        Category & _root;

};

//Mylogger * Mylogger::_pInstance=NULL;//如果这么写，其他的几个.cc文件里都加载了这一句,则会重加载



#define  prefix(msg) string().append(__FILE__)\
        .append("-").append(__FUNCTION__)\
        .append("-").append(std::to_string(__LINE__))\
        .append(msg).c_str()
//用宏来解决函数里打印的行号的问题,但是宏应该放到头文件里

#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg)) //通过宏定义缩短函数的长度
#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define LogError(msg) Mylogger::getInstance()->error(prefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg))


#endif
