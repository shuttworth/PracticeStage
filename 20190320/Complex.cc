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
        cout<<_dreal<<" +  "<<_dimag <<" i "<<endl;  //需要运算符重载才可以实现
    }
};

int main()
{
    Complex c1(3,4);
    Complex c2(5,6);
    c1.display();
    c2.display();
    return 0;
}

