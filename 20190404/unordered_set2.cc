#include <math.h>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

int test0()
{
    unordered_set<int>numbers={4,3,9,6,2,5,7,4};

    unordered_set<int>::iterator it;
    for(it=numbers.begin();it!=numbers.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
    
    cout<<"numbers.count(1)="<<numbers.count(1)<<endl;
    cout<<"numbers.count(0)="<<numbers.count(0)<<endl;

    it=numbers.find(7);
    cout<<"numbers.find(7) ";
    if(it!=numbers.end())
    {
        cout<<"查找成功"<<endl;
    }else
    {
        cout<<"查找失败"<<endl;
    }
    it=numbers.find(11);
    cout<<"numbers.find(11) ";
    if(it!=numbers.end())
    {
        cout<<"查找成功"<<endl;
    }else
    {
        cout<<"查找失败"<<endl;
    }
    return 0;
}


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
            <<")"<<endl;
    }

    float getDistance() const 
    {
        return sqrt(_ix * _ix+_iy * _iy);
    }

    int getX() const {
        return _ix;
    }
    int getY() const {
        return _iy;
    }

    friend std::ostream & operator <<(std::ostream & os,const Point & rhs);  //左边是cout，右边是Point,重载这个<<
    friend bool operator ==(const Point & lhs,const Point & rhs);
};

std::ostream & operator << (std::ostream & os,const Point & rhs)
{
    os<<"("<<rhs._ix
        <<","<<rhs._iy
        <<")"<<endl;
    return os;
}


bool operator == (const Point & lhs,const Point & rhs)
{
    return (lhs._ix==rhs._ix)&&(rhs._ix==rhs._iy);
}

struct MyEqual
{
    bool operator() (const Point & lhs,const Point & rhs) const
    {
        return (lhs.getX()==rhs.getX())&&(lhs.getY()==lhs.getY());
    }
};


namespace std
{
template <>
    struct hash<Point>
{
    size_t operator () (const Point & pt) const
    {
       return (pt.getX()<<1)^(pt.getY()>>1); 
    }
};
}

struct MyHasher
{
    size_t operator () (const Point & pt) const
    {
        return (pt.getX()<<1)^(pt.getY()>>1);
    }
};


void test1()
{
    unordered_set<Point> numbers ={
        {3,2},
        {1,4},
        {5,2},
        {3,4},
        {5,6}
    };

}





int main()
{
    test0();
}
