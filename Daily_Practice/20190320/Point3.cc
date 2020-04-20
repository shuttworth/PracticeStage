#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
//using namespace std; //一般不要使用namespace std；
class Point;  //类的前向声明

class Line
{
public:
    Line(){ cout <<"Line()"<<endl; }
    ~Line() {cout<<"~Line()"<<endl;}
    float distance(const Point & lhs,const Point & rhs);
    void setPoint(Point  & pt,int x,int y);   
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
        cout<<" Point(int ix=0,int iy=0)"<<endl;
    }

    void print() const
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }


    friend Line; //现在Line是Point的友元,友元的关系并不是相互的，是单向的，A->B,B->C,不具备传递性,不能被继承
    //友元之非成员函数
   // friend float Line::distance(const Point & lhs,const Point & rhs);
};


float Line::distance(const Point & lhs,const Point & rhs)  //直接这么写，是无法访问的，要设为友元
{
   // return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
    return sqrt(pow(lhs._ix-rhs._ix,2)+pow(lhs._iy-rhs._iy,2));
}


void Line::setPoint(Point & pt,int ix,int iy)
{
    pt._ix=ix;
    pt._iy=iy;
}


int main()
{
    Line();
    Point pt1(1,2);
    Point pt2(4,6);
    pt1.print();
    cout<<" --->  ";
    pt2.print();
    cout<<" 的距离 "<<endl;
    cout<<Line().distance(pt1,pt2)<<endl;

    Line().setPoint(pt1,10,11);
    cout<<"pt1 = ";
    pt1.print();

    return 0;
}

