#include <iostream>

namespace op{
class Operation{
public:
    Operation()
    {}
    
    Operation(double number1,double number2)
    :_number1(number1)
    ,_number2(number2) 
    {

    }
    
    virtual ~Operation(){}

    void setNumber1(double number1)
    {
        _number1=number1;
    }

    void setNumber2(double number2)
    {
        _number2=number2;
    }

    double getNumber1()
    {
        return _number1;
    }

    double getNumber2()
    {
        return _number2;
    }

    virtual double GetResult()
    {
        double result = 0;
        return result;
    }


private:
    double _number1;
    double _number2;
};    


class OperationAdd
:public Operation
{
public:
    OperationAdd(double number1,double number2)
    :Operation(number1,number2)  //子类的构造函数的初始化列表中初始化基类
    {}


    double GetResult() override
    {
        double result = getNumber1()+getNumber2();
        return result;
    }
};


class OperationSub
:public Operation
{
public:
    OperationSub(double number1,double number2)
    :Operation(number1,number2)
    {}

    double GetResult() override
    {
        double result = getNumber1() - getNumber2();
        return result;
    }
};


class OperationMulti
:public Operation
{
public:
    OperationMulti(double number1,double number2)
    :Operation(number1,number2)
    {}
    
    double GetResult() override
    {
        double result = getNumber1() * getNumber2();
        return result;
    }
};


class OperationDel
:public Operation
{
public:
    OperationDel(double number1,double number2)
    :Operation(number1,number2)
    {}
    
    double GetResult() override
    {
        if(!getNumber2()){
            printf("除数不能为0");
            return -1; //这个地方不想给返回值，要用throw？
        }
        double result = getNumber1()/getNumber2();
        return result;
    }
};



}//end of namespace op

