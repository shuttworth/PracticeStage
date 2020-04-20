#include <iostream>

using std::cout;
using std::endl;

class stack
{
public:
    stack(int size)
        :_array(new int[size]())
         ,_top(-1)
         ,_size(size)  //这里的顺序严格按照private初始化的顺序来写
    {}

    bool empty() const
    {
        return _top==-1;
    }

    bool full() const 
    {
        return _top==_size -1;
    }

    int top()
    {
        if(!empty())
        {
            cout << "栈顶值为 ==" <<_array[_top] <<endl;
        }
        else cout << "栈已空" << endl;
        return 0;
    }

    void push(int value)
    {
        if(!full())
        {
            _array[++_top]=value; //因为_top的初始值为-1
        }else cout << "栈已满" << endl; 
    }

    void pop()
    {
        if(!empty())
        {
            --_top; // 通过控制栈顶指针就可以实现，pop 功能
           // delete _array[_top];
        }else
            cout<< "栈已空" <<endl;
    }

    ~stack()//之前的队列不需要析构函数，因为没有new开辟空间
    {
        delete [] _array; //此处的析构函数有重要作用，就是把开的数组空间给回收了
        cout << "~stack" <<endl;
    }
private:
    int * _array;
    int _top;
    int _size;

};


int main()
{
    stack st1(10);
    st1.push(10);
    st1.push(12);
    st1.push(14);
    st1.top();
    st1.pop();
    st1.top();

    return 0;
}
