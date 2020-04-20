#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::make_pair;

template <typename Container>
void display(const Container &c)
{
    typename Container::const_iterator cit=c.begin();
    while(cit!=c.end())
    {
        cout<<cit->first<<"--->"<<cit->second<<endl;
        ++cit;
    }
}


void test0()
{
    map<int,string>cities{
        pair<int,string>(1,"北京"),
        pair<int,string>(2,"上海"),
        pair<int,string>(3,"广州"),
        pair<int,string>(4,"深圳"),
        pair<int,string>(5,"杭州"),
        pair<int,string>(2,"武汉"),
        pair<int,string>(3,"南京"),
    };

    display(cities);
    cout<<cities[1]<<endl; //存在直接打印
    cout<<cities[6]<<endl; //不存在直接创建

    cout<<endl;
    display(cities);
    cities[6]="合肥";
    cout<<"after curruption"<<endl;
    display(cities);

}

void test1()
{
    map<string,string>cities{
        pair<string,string>("11","北京"),
        make_pair("22","上海"),
        make_pair("33","深圳"),
        make_pair("44","深圳"),
        make_pair("55","杭州"),
        make_pair("22","武汉"),
    };

    display(cities);
    cout<<"cities['11']";
    cout<<cities["11"]<<endl;

    cout<<cities["66"]<<endl;
    cout<<endl;
    display(cities);
    cities["66"]="武汉";
    cout<<"after curruption"<<endl;
    display(cities);

    //查找
    cout<<"11's count"<<cities.count("11")<<endl;
    cout<<"77's count"<<cities.count("77")<<endl;
    display(cities);
    cout<<endl;

    auto it=cities.find("77");
    if(it!=cities.end())
    {
        cout<<it->first<<"--->"<<it->second<<endl;
    }else
    cout<<"can not find 77"<<endl;
    cout<<endl;
    display(cities);

    auto ret=cities.insert(make_pair("77","西安"));
    if(ret.second) //返回值ret的前半部分是"66","西安",后半部分是bool
    {
        cout<<"successly add"<<endl;
        cout<<"RET information"<<endl;
        cout<<ret.first->first<<"--->"<<ret.first->second<<endl;
    }
    else {
        cout<<"insert default"<<endl;
        cout<<"RET information"<<endl;
        cout<<ret.first->first<<"--->"<<ret.first->second<<endl;
    }
    cout<<endl;
    display(cities);
}

int main()
{
    //test0();
    test1();
    return 0;
}

