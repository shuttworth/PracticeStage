//策略模式的核心要义是，CashSuper是抽象类，内部留有接口，通过子类继承后override重写具有多态特性
//在CashContext中，只需要创建一个CashSuper指针，就可以通过new 子类 来调用不同重写后的方法
//客户端只能摸到CashContext，摸不到CashStrategy的影子，保护性很好

namespace stg{

class CashSuper{
public: 
    virtual double acceptCash(double) = 0;
    virtual ~CashSuper() {}
};

class CashNormal
:public CashSuper
{
public:
    double acceptCash(double cash) override{
        return cash;
    }
};


class CashRebate
:public CashSuper
{
public:
    CashRebate(double moneybate)
    :_moneybate(moneybate)
    {}
    
    double acceptCash(double cash) override{
        return cash * _moneybate;
    }
private:
    double _moneybate;
};

class CashReturn
:public CashSuper
{
public:
    CashReturn(double total,double back)
    :_total(total)
    ,_back(back) 
    {}
    
    double acceptCash(double cash) override{
        double ret = cash;
        if(ret>_total)
            ret -= _back; 
        return ret;
    }
private:
    double _total;
    double _back;
};



}//end of namespace stg
