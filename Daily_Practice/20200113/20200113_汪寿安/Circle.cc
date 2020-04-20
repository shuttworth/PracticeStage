#include <iostream>

using std::cout;
using std::endl;

#define PI 3.141592

class Circle
{
public:
    Circle()
        :_r(0)
    {}

    Circle(double  r )     //创建Circle对象时将半径初始化为r      
        :_r(r)
    {}

   double getArea()
   {
       return PI*_r*_r;
   }                     //获取圆的面积            
   double getPerimeter( )
   {
       return PI*_r*2;
   }                    //获取圆的周长              
    void  show( ) 
    {
        cout<<"圆的周长"<<getPerimeter()<<endl;
        cout<<"圆的面积"<<getArea()<<endl;
    }                   //将圆的半径、周长、面积输出到屏幕 

private:
    int _r;
};

int main()
{
    return 0;
}

