#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point()
    :_ix(0)
    ,_iy(1)
    {
        cout << "Point()" <<endl;
    }
    Point(int ix,int iy)
    :_ix(ix)
     ,_iy(iy)
    {
        cout << "Point(int ix,int iy)" <<endl;
    }


void print(/*Point const*const this */) const
{
    cout<<"void print()const"<<endl;
    cout<<"("<<this->_ix
        <<","<<this->_iy
        <<")"<<endl;

}

/*~Point()
{
    cout << "~Point()" << endl;
}*/
private:
    int _ix;
    int _iy;

};

void test0()
{
    Point pt[5]={Point(1,2),Point(3,4),Point(5,6)};
    pt[0].print();
    pt[1].print();
    pt[2].print();
    pt[3].print();
    pt[4].print();
   // return 0;
}

int main()
{
    test0();
    return 0;
}

