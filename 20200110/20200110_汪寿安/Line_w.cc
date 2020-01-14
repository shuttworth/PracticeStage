#include "Line_w.h"
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl
{
public:
    LineImpl(int x1,int y1,int x2,int y2);
    ~LineImpl()
    {cout<<"~LineImpl()"<<endl;}

    void printLineImpl() const
    {
        _pt1.printPoint();
        cout<<"------>";
        _pt2.printPoint();
        cout<<endl;
    }
    


private:
    class Point
    {
    public:
        Point(int ix=0,int iy=0)
            :_ix(ix)
             ,_iy(iy)
        {
            cout<<"Point(int ix=0,int iy=0)"<<endl;
        }

        void printPoint() const;

        ~Point(){cout<<"~Point()"<<endl;}


    private:
        int _ix;
        int _iy;
    };

private:
    Point _pt1;
    Point _pt2; //之所以放在下面，是因为需要有Point类型的定义

};


void Line::LineImpl::Point::printPoint() const
{
    cout<<"("<<_ix
        <<","<<_iy
        <<")";
}

/* void testIfPrivate(Line::LineImpl::Point){} */


Line::LineImpl::LineImpl(int x1,int y1,int x2,int y2)
:_pt1(x1,y1)
,_pt2(x2,y2)
{
    cout<<"Line::LineImpl::LineImpl(int,int,int,int)"<<endl;
}


Line::Line(int x1,int y1,int x2,int y2)
:_pimpl(new LineImpl(x1,y1,x2,y2))
{
    cout<<"Line(int,int,int,int)"<<endl;
}


Line::~Line()
{
    delete _pimpl;
    cout<<"~Line()"<<endl;
}


void Line::printLine() const
{
    _pimpl->printLineImpl();
}


int main()
{
    Line Line(2,4,6,8);
    Line.printLine();
    return 0;
}















