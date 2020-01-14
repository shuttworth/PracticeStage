#include <iostream>

using std::cout;
using std::endl;

class Line {
public:
    Line(int x1, int y1, int x2, int y2);
    void printLine() const;
private:
    class Point {
    public:
        Point(int x = 0, int y = 0)
            : _x(x), _y(y)
        {}
        void print() const;
    private:
        int _x;
        int _y;
        
    };
    Point _pt1;
    Point _pt2;
    
};

Line::Line(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1), _pt2(x2, y2)
{}
void Line::printLine() const
{
    _pt1.print();
    cout << " ---> ";
    _pt2.print();
    cout << endl;
}

void Line::Point::print() const
{
    cout<<"("<<_x
        <<","<<_y
        <<")";
}



