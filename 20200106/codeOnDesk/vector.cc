#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void printvectorstatus(vector<int>&vec)
{
    cout<<"vec.size=="<<vec.size()<<endl
        <<"vec.capacity=="<<vec.capacity()<<endl;
}

int main()
{
    vector<int>number;
    number.reserve(3);
    printvectorstatus(number);

    number.push_back(1);
    cout<<"having push number 1"<<endl;
    printvectorstatus(number);
    number.push_back(2);
    cout<<"having push number 2"<<endl;
    printvectorstatus(number);
    number.push_back(3);
    cout<<"having push number 3"<<endl;
    printvectorstatus(number);
    number.push_back(4);
    cout<<"having push number 4"<<endl;
    printvectorstatus(number);
    number.push_back(5);
    cout<<"having push number 5"<<endl;
    printvectorstatus(number);
    number.push_back(6);
    cout<<"having push number 6"<<endl;
    printvectorstatus(number);
    number.push_back(7);
    cout<<"having push number 7"<<endl;
    printvectorstatus(number);
//从打印结果可以看到：动态增加容量十分有意思，有其自身规律
    number.pop_back();
    printvectorstatus(number);
    number.pop_back();
    printvectorstatus(number);
    number.pop_back();
    printvectorstatus(number);
    number.pop_back();
    printvectorstatus(number);
    number.pop_back();
    printvectorstatus(number);
    
    return 0;
}
