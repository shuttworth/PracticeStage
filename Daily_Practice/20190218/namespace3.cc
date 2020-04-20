#include <iostream>
using namespace std;

using std::cout;//推荐使用
using std::endl;

namespace wd
{
int num=10;
void display()
{
    cout<<"wd::display()"<<endl;
}
}
int main()
{
    std::cout << "num=" <<wd::num << std::endl;
    wd::display();
    return 0;
}

