#include <math.h>
#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;


template <typename Container>
void display(const Container & c)
{
    for(auto& elem :c)
    {
        cout<<elem<<"  ";
    }
    cout<<endl;
}

void test0()
{
    int arr[10]={4,5,2,3,8,9,7,1};
    set<int>numbers(arr,arr+8);  //左闭右开,默认std::less<int>,升序、从小到大排列
    display(numbers);

    size_t size=numbers.size();
    cout<<"size="<<size<<endl;
    size_t cnt=numbers.count(1);
    cout<<"cnt="<<cnt<<endl;
    cnt=numbers.count(0);
    cout<<"cnt="<<cnt<<endl;

    set<int>::iterator it=numbers.find(0); //find的用法：指向键等于 key 的元素的迭代器。若找不到这种元素，则返回尾后（见 end() ）迭代器。
   // cout<<"it="<<it<<endl;
    cout<<"*it="<<*it<<endl;
}

void test1()
{
    int arr[10]={4,13,2,3,8,10,6,1};
    set<int,std::greater<int>>numbers(arr,arr+8);  //实现从大到小排列
    display(numbers);

    size_t cnt=numbers.count(4);
    cout<<"cnt="<<cnt<<endl;
    cnt=numbers.count(9);
    cout<<"cnt="<<cnt<<endl;

    set<int>::iterator it=numbers.find(11);
    cout<<"*it"<<*it<<endl;

    if(numbers.find(11)==numbers.end())
    {
        cout<<"11不存在"<<endl;
    }

    //std::pair 是一个提供存储二个相异对象于一个单元的方式的结构体模板。
    std::pair<set<int>::iterator,bool> ret=numbers.insert(11);  //set的insert返回值为两个部分，第一是迭代器位置，第二是插入是否成功的true、false
    if(ret.second)
    {
        cout<<"元素添加成功"<<endl;
        cout<<*ret.first<<endl;
    }else
    {
        cout<<"元素添加失败"<<endl;
        cout<<*ret.first<<endl;
    }
    cout<<endl;

    int arr2[3]={13,14,15};
    numbers.insert(arr2,arr2+3); //numbers 数组已经定义过了，现在不能再重定义这个数组了，需要insert
    display(numbers);

    
}


int main()
{
   // test0();
    test1();
    return 0;
}

