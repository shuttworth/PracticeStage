#include <iostream>
using std::cout;
using std::endl;

class Complex
{
private:
    double _dreal;
    double _dimag;

public:
    Complex(double dreal,double dimag)
        :_dreal(dreal)
         ,_dimag(dimag)
    {
        cout<<"Complex(double dreal,double dimag)"<<endl;
    }


    void display() const
    {
        cout<<_dreal<<" + "<<_dimag <<"i"<<endl;  //需要运算符重载才可以实现
    }

   // friend Complex operator+(const Complex & lhs,const Complex & rhs);
    //运算符重载用友元来帮助实现
    
    
    //采用成员函数来实现
    Complex operator + (const Complex & rhs)
    {
        return Complex(_dreal+rhs._dreal,_dimag+rhs._dimag);
    }
    
};

/*
Complex operator+(const Complex & lhs,const Complex & rhs)
{
    return Complex(lhs._dreal+rhs._dreal,
                   lhs._dimag+rhs._dimag);
}
*/


int main()
{
    Complex c1(3,4);
    Complex c2(5,6);
    cout<<"c1= ";
    c1.display();
    cout<<"c2= ";
    c2.display();
   
    Complex c3=c1+c2;
    cout<<"c3= ";
    c3.display();
    return 0;
}

