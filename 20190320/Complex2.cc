#include <iostream>
using std::cout;
using std::endl;

class Complex
{
private:
    double _dreal;
    double _dimag;

public:
    Complex(double dreal=0,double dimag=0)
        :_dreal(dreal)
         ,_dimag(dimag)
    {
        cout<<"Complex(double dreal,double dimag)"<<endl;
    }


    void display() const
    {
        if(_dreal)
        {
            cout<<_dreal; //只有>0的时候才执行这句话
        }
        if(_dimag>0)
        {
            cout<<"+"<<_dimag<<"i"<<endl;
        }
        else if(_dimag<0)
        {
            cout<<"-"<<_dimag * (-1)<<"i"<<endl;
        }
        cout<<endl;
    }



    //复合赋值运算符推荐以成员函数形式进行重载
    //表达式执行结束后，对象本身发生变化，所以返回* this
    Complex & operator +=(const Complex & rhs)
    {
        _dreal+=rhs._dreal;
        _dimag+=rhs._dimag;
        return * this;
    }

    //前置,返回值是引用,前置的执行效率高于后置
    Complex & operator ++()
    {
        ++ _dreal;
        ++ _dimag;
        return * this;
    }

    //后置,返回值是对象
    Complex operator ++(int) //int 作为一个标志位，以区别于前置
    {
        Complex temp(*this);
        ++ _dreal;
        ++ _dimag;
        return temp;
    }




    friend Complex operator+(const Complex & lhs,const Complex & rhs);
    //运算符重载用友元来帮助实现
};

#if 1
//双目运算符，加减乘除，推荐用这种方式重载
Complex operator+(const Complex & lhs,const Complex & rhs)
{
    return Complex(lhs._dreal+rhs._dreal,
                   lhs._dimag+rhs._dimag);
}
#endif

//加法也可以用+=符号来完成


int test0()
{
    Complex c1(3,4);
    Complex c2(5,6);
    c1.display();
    c2.display();

    Complex c3=c1+c2;
    c3.display();
    return 0;
}



void test1()
{
    Complex c1(1,1);
    c1.display();
    Complex c2(0,0);
    c2.display();
    Complex c3(-1,-1);
    c3.display();
    Complex c4(0,-2);
    c4.display();
}


void test2()
{
    Complex c1(1,1);
    Complex c2=c1+5;//这里可以执行，是因为给初构造函数赋了初值
    cout<<"c2= "; // 5会被隐式转换
    c2.display();

    Complex c3=5+c1;
    cout<<"c3= ";
    c3.display();
}


int main()
{
   // test1();
    test2();
    return 0;
}
