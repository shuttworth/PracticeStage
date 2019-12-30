#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    Point()
        :_ix(0)
         ,_iy(1)
    {
        cout<<"Point()"<<endl;
    }

    Point(int ix,int iy)
        :_ix(ix)
         ,_iy(iy)
    {
        cout<<"Point(int ix,int iy)"<<endl;

    }

    void print()
    {
        cout<<"("<<_ix
        <<","<<_iy<<")"<<endl;
    }
private:
    int _ix;
    int _iy;
};


void test0(){
    Point Po[5]={Point(1,2),Point(3,4),Point(5,6)};
    Po[0].print();
    Po[1].print();
    Po[2].print();
    Po[3].print();
    Po[4].print();
}

int main()
{
    test0();
    return 0;
}

