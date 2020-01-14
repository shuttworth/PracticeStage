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

#if 0
① 1个成员变量，圆柱体的高；
② 构造方法           
                        Cylinder (double r, double  h) //创建Circle对象时将半径初始化为r         
③ 成员方法
                            double getVolume( )   //获取圆柱体的体积             
                    void  showVolume( )   //将圆柱体的体积输出到屏幕  
                编写应用程序，创建类的对象，分别设置圆的半径、圆柱体的高，
                            计算并分别显示圆半径、圆面积、圆周长，圆柱体的体积。
#endif

class Cylinder:public Circle
{
public:
    Cylinder (double r, double  h)
    :Circle(r)
     ,_h(h)
    {}

    double getVolume()
    {
        return _h*getArea();
    }

    void  showVolume()
    {
        cout<<"圆柱体的体积是"<<getVolume()<<endl;
    }


private:
    int _h;
};











int main()
{
    return 0;
}

