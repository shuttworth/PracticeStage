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
    printvectorstatus(number);
    number.push_back(2);
    printvectorstatus(number);
    number.push_back(3);
    printvectorstatus(number);
    number.push_back(4);
    printvectorstatus(number);
    number.push_back(5);
    printvectorstatus(number);
    number.push_back(6);
    printvectorstatus(number);
    number.push_back(7);
    printvectorstatus(number);
//从打印结果可以看到：动态增加容量十分有意思，有其自身规律
    return 0;
}
