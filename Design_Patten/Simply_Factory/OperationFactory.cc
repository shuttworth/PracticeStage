#include "Operation.cc"
#include <stdio.h>
/* #include <string.h> */
/* using std::string; */


namespace op{

class OperationFactory{

    //下面提现了简单工厂的不足，即 扩展的时候需要改createOperation的源代码
    //后续的改进：工厂模式————采取的是把工厂给抽象化，具体的工厂继承自抽象工厂，利用多态，开放——封闭原则

public:
    static Operation *  createOperation(double number1,double number2,char msg)
    {
        Operation * ret = NULL;
        switch(msg) //只能对基本类型做判断
        {
        case '+':
            ret = new OperationAdd(number1,number2); //多态的使用，基类指针可以指向创建的派生类的对象
            break;
        case '-':
            ret = new OperationSub(number1,number2);
            break;
        case '*':
            ret = new OperationMulti(number1,number2);
            break;
        case '/':
            ret = new OperationDel(number1,number2);
            break;
        }

        return ret;
    }

};




}//end of namespace op;
