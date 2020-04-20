#include <iostream>
using namespace std;

namespace wd
{
int num=10;
void display()
{
    cout<<"wd::display()"<<endl;
}
}

void cout()
{

}

int main()
{
    std::cout << "num=" <<wd::num << std::endl;
    wd::display();
    return 0;
}

