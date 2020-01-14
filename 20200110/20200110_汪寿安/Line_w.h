#pragma once //效果等价于ifndef define endif

class Line
{
public:
    Line(int x1,int y1,int x2,int y2) ;
    ~Line() ;

    void printLine() const;

    class LineImpl;  //具体的实现都放在LineImpl里

private:
    LineImpl * _pimpl; //这个指针将会有作用
};

