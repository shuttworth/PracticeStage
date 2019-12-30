#include <iostream>
using namespace std;

using std::cout;
using std::endl;

namespace wd{
int num=10;
void display(){
    cout<<"wd::display(1)"<<endl;
}
};

int main()
{
    cout<<"num="<<wd::num<<endl;
    wd::display();
    return 0;
}

