#include "CashStrategy.cc"
#include <string.h>
#include <iostream>
using std::string;

namespace stg{

class CashContext{
public:
    CashContext(string msg)
    {
        if(msg=="正常收费")
        {
            _ptr = new CashNormal();
        }
        else if(msg=="满300减100")
        {
            _ptr = new CashReturn(300,100);
        }
        else if(msg=="打8折")
        {
            _ptr = new CashRebate(0.8);
        }
    }

    double getResult(double cash)
    {
        return _ptr->acceptCash(cash);
    }

private:
    CashSuper * _ptr;  
    //个人感觉，这是策略模式和简单工厂模式最大的区别；把基类CashSuper包装起来，不让客户端用到，全程只用到CashContext这一个量
    //使得具体的收费方法彻底和客户端相分离
};




}// end of namespace stg
