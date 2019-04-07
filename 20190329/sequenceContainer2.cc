#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;
using std::sort;


template<typename Container>
void display(Container & c)  //模板的指针遍历打印
{
    typename Container::const_iterator cit=c.begin();
    while(cit!=c.end())
    {
        cout<<*cit<<"  ";
        ++cit;
    }
    cout<<endl;
}

void test0()
{
    vector<int>numbers {5,3,9,7,8,2};
    sort(numbers.begin(),numbers.end());
    display(numbers);
}

void test1() //list 的各种用法比较重要
{
    list<int>numbers {5,3,9,7,8,2};
    numbers.sort();
    display(numbers);

    list<int>numbres2 {16,20,9,55,17};
    numbres.splice(it)
}


int main()
{
    test0();
    test1();
    return 0;
}

