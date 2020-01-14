#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String(const String &rhs)//String &rhs = func();
    :_pstr(rhs._pstr)
    ,_count(rhs._count + 1)
    {
        ++rhs._count;
    }
private:
    char *_pstr;
    static int _count;
};
int main(int argc, char **argv)
{
    String s1;
    cout << "Hello world" << endl;
    return 0;
}

