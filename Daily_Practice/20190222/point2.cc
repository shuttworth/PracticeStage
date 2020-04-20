#include <iostream>

using std::cout;
using std::endl;

class Point
{
    public:
        Point(int ix,int iy)
        : _ix(ix)
        , _iy(iy)
    {
        cout<<"point(int,int)"<<endl;
    }

        Point(const Point & rhs)
        :_ix(rhs._ix)
         ,_iy(rhs._iy)
    {
        cout << "Point(const Point &rhs)" << endl;
    }

        ~Point()
        {
            cout<<"~point()"<<endl;
        }
    private:
        int _ix;
        int _iy;
};

int test0(void)
{
    Point pt1(1,2);
    Point pt2=pt1;
    return 0;
}



int main(void)
{
    test0();
    Point pt(1,2);
    return 0;
}

