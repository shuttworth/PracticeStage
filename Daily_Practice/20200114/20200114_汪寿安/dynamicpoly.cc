#include <string.h>

#include <iostream>

using std::cout;
using std::endl;
using std::string;
#if 0
编写一个抽象类Figure，该类拥有：
① 1个成员变量，存放图形的名字（是否该设计成private/protected?）
② 2个纯虚函数
virtual double getArea( )=0
virtual string getName( )=0
virtual void show()=0           //打印图形的相关信息
#endif
#define PI 3.141592

class Figure
{   
    /* Figure(const char *name) */
    /* :_name(name) */
    /* { */
    /*     cout<<"Figure(const char *)"<<endl; */
    /* } */
public:
    virtual double getArea( )=0;
    virtual string getName( )=0;
    virtual void show()=0;

protected:
    string _name;
};

#if 0
编写一个圆类Circle，让其继承自Figure类，该类拥有： 
① 1个成员变量，存放圆的半径；（是否该设计成private/protected?）
    ② 2个构造方法
    Circle( )              // 将半径设为0           
Circle(double  r )     //创建Circle对象时将半径初始化为r      
    ③ 3个成员方法           
    double getRadius( )         //获取圆的半径
    double getPerimeter( )      //获取圆的周长
    virtual double getArea( )   //获取圆的面积
virtual string getName( )   //获取圆的名字           
void  show( )               //将圆的半径、周长、面积输出到屏幕 
#endif

    class Circle:public Figure
{
public:
    Circle()
        :_r(0)
    {}
    Circle(double r)
        :_r(r)
    {}

    double getRadius( )
    {
        return _r;
    }         //获取圆的半径
    double getPerimeter( )
    {
        return 2*PI*_r;
    }//获取圆的周长
    virtual double getArea( )
    {
        return PI*_r*_r;
    }//获取圆的面积
    virtual string getName( )
    {
        return _name;
    }//获取圆的名字           
    void  show( )
    {
        /* cout<<"圆的名字是"<<getName()<<endl; */
        cout<<"圆的半径是"<<_r<<endl;
        cout<<"圆的周长是"<<getPerimeter()<<endl;
        cout<<"圆的面积是"<<getArea()<<endl;
    }//将圆的半径、周长、面积输出到屏幕 

protected:
    double _r;
};

/* 编写一个圆柱体类Cylinder，它继承于上面的Circle类，还拥有： */ 
/*     ① 1个成员变量，圆柱体的高； */
/*         ② 构造方法 */           
/*                 Cylinder (double r, double  h) //创建Circle对象时将半径初始化为r */         
/*         ③ 成员方法 */
/*                 覆盖Circle的getArea( )   //获取圆柱体的表面积 */ 
/*             覆盖Circle的getName( )   //获取图形的名字 */
/*             double getHeight( )      //获取圆柱体的高 */
/*             double getVolume( )      //获取圆柱体的体积 */           
/*             void  show()             //将圆柱体的高、表面积、体积输出到屏幕 */ 

class Cylinder:public Circle
{
public:
    Cylinder(double r,double h)
    :Circle(r)
     ,_h(h)
    {
        /* cout<<"Cylinder(double , double)"<<endl; */
    }
    
    virtual double getArea( )
    {
        return 2*PI*_r*_r+_h*2*PI*_r;
    }//获取圆柱体的面积
    virtual string getName( )
    {
        return _name;
    }//获取图形的名字           
            
    double getHeight( )
    {
        return _h;
    }//获取圆柱体的高
    double getVolume( )
    {
        return _h * Circle::getArea();
    }//获取圆柱体的体积           
            
    void  show()
    {
        cout<<"圆柱体的高"<<_h<<endl;
        cout<<"圆柱体的表面积"<<getArea()<<endl;
        cout<<"圆柱体的体积"<<getVolume()<<endl;
    }   //将圆柱体的高、表面积、体积输出到屏幕 

private:
        double _h;
};
    /* ① 创建类的对象，分别设置圆的半径、圆柱体的高 */
    /*     ② 计算并分别显示圆半径、圆面积、圆周长， */
    /*         ③ 计算并分别显式圆柱体的高、表面积、体积。 */

int main()
{
    Figure * p1=new Circle(5);
    Figure * p2=new Cylinder(5,9);

    /* Circle c1(5); */
    /* Cylinder c2(5,9); */
    p1->show();
    p2->show();
    return 0;
}

