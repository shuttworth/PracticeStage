#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

class Point
{
private:
    int _ix;
    int _iy;
public:
    Point(int ix=0,int iy=0)
        :_ix(ix)
         ,_iy(iy)
    {}

    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

    friend std::ostream & operator << (std::ostream & os,const Point & rhs);
};

std::ostream & operator << (std::ostream & os,const Point & rhs) //两个传参分别是<<左边的ostream类型的cout，和<<右边的要输出信息的Point类型的信息,本来的cout<<Point
{
    os<<"("<<rhs._ix
      <<","<<rhs._iy
      <<")"<<endl;
    return os;
}

template <typename  Container>
void display(const Container & c)
{
    typename Container::const_iterator cit=c.begin(); //const_iterator只能访问值，不能改变值
    while(cit!=c.end())
    {
        cout<<*cit<<"  ";
        ++cit;
    }
    cout<<endl;
}

void test0()
{
    vector<int> numbers{1,2,3,4,5,6};

    int arr[3]={11,12,13};
    auto vit = numbers.begin();
    std::advance(vit,4);
    numbers.insert(vit,arr,arr); // 本种用法里，在指定位置loc前插入区间[start, end)的所有元素，如果写arr arr这样左闭右开没有元素
    numbers.shrink_to_fit();
    display(numbers);
}


void test1()
{
    vector<Point> numbers(10,Point(1,2));
    vector<Point>::iterator it; //iterator用来访问容器vector中的内容

    for(it=numbers.begin();it<numbers.end();++it)
    {
        cout<<*it<<"  ";
    }
    cout<<"vextor numbers[3] ="<<numbers[3]<<endl;
    cout<<endl;
}


void test2()
{
    deque<int> numbers{1,2,3,4,5,6};

    int arr[3]={11,12,13};
    auto vit = numbers.begin();
    std::advance(vit,4);
    numbers.insert(vit,arr,arr+3); // 本种用法里，在指定位置loc前插入区间[start, end)的所有元素，如果写arr arr这样左闭右开没有元素
    numbers.shrink_to_fit();
    cout<<"deque numbers[3] ="<<numbers[3]<<endl;
    display(numbers);

}

void test3()
{
    list<int> numbers{1,2,3,4,5,6};
    int arr[3]={11,12,13};
    auto vit=numbers.begin();
    std::advance(vit,3);
    numbers.insert(vit,arr,arr+3);
    display(numbers);
    numbers.clear();
    cout<<"执行了clear操作以后"<<endl;
    display(numbers);  //什么都打印不出来

}



int main()
{
   // test0();
  // test1();
   //test2();
    test3();
}






/*iterator insert( iterator loc, const TYPE &val ); 
void insert( iterator loc, size_type num, const TYPE &val ); 
void insert( iterator loc, input_iterator start, input_iterator end ); 

insert() 函数有以下三种用法: 

在指定位置loc前插入值为val的元素,返回指向这个元素的迭代器, 
在指定位置loc前插入num个值为val的元素 
在指定位置loc前插入区间[start, end)的所有元素 . 
*/
