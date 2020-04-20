#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class Point;

class Line
{
public:
    Line()
    {}
        // {cout<<"Line"<<endl;}
    ~Line()
    {}
        //{cout<<"~Line"<<endl;}
    float distance(const Point & lhs,const Point & rhs);//&绑定后，不想修改，因此const进行限制
    void setPoint(Point & pt,int x,int y);
};

class Point
{
private:
    int _ix;
    int _iy;
public:
    Point(int ix=0,int iy=0)
        :_ix(ix)
         ,_iy(iy)
    {
        cout<<"Point(int ix=0,int iy=0)"<<endl;
    }

    void print() const
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")";
    }

    //核心内容
    friend Line;
};

float Line::distance(const Point & lhs,const Point & rhs)
{
    return sqrt(pow(lhs._ix-rhs._ix,2)+pow(lhs._iy-rhs._iy,2));//pow(a,b) 求a的b次幂；sqrt开平方
}

void  Line::setPoint(Point &pt,int ix,int iy)
{
    pt._ix=ix;
    pt._iy=iy;
}

int main()
{
    Line();
    Point pt1(2,3);
    Point pt2(5,7);
    pt1.print();
    cout<<" --->  ";
    pt2.print();
    cout<<"的距离为：";
    cout<<Line().distance(pt1,pt2);

    Line().setPoint(pt1,10,11);
    cout<<endl;
    cout<<"pt1 is";
    pt1.print();
    cout<<endl;
    return 0;
}

