#include <iostream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;


namespace  pro{

class girl
{
public:
    girl(string name)
    :_name(name)
    {}

    string getname() const
    {
        return _name;
    }

private:
    string _name;

};


class Givegift{
public:
    //C++没有纯粹的interface关键字，只能用抽象的方法来实现接口
    //C# 是有interface关键字的
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
    virtual ~Givegift(){}
};

class Pursuit
:public Givegift
{
public:
    Pursuit(girl mm)
    :_mm(mm)
    {}
    
    void GiveDolls()
    {
        cout<<"give "<<_mm.getname()<<" Dolls"<<endl;
    }

    void GiveFlowers()
    {
        cout<<"give "<<_mm.getname()<<" Flowers"<<endl;
    }

    void GiveChocolate()
    {
        cout<<"give "<<_mm.getname()<<" Chocolate"<<endl;
    }

private:
    girl _mm;

};





class Proxy
:public Givegift
{
public:
    Proxy(girl mm)
    :pur(Pursuit(mm))    
    {}

    
    void GiveDolls()
    {
        pur.GiveDolls();
    }

    void GiveFlowers()
    {
        pur.GiveFlowers();
    }

    void GiveChocolate()
    {
        pur.GiveChocolate();
    }

private:
    Pursuit  pur;


};








}//end of namespace pro


