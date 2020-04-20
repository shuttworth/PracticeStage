#include <iostream>

using std::cout;
using std::endl;

int &func()
{
    static int a = 10;
    return a;
}
int main(int argc, char **argv)
{
    func() = 10;
    return 0;
}

