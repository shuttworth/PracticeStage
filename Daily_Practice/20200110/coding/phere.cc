#include <iostream>

using namespace std;

int num = 1;
int x = 2;
class Example {
public:
    void print(int num)
    {
        cout << "形参num = " << num << endl;
        cout << "数据成员num = " << this->num << endl;
        cout << "数据成员num = " << Example::num << endl;
        cout << "全局变量num = " << ::num << endl; //全局变量存在匿名区
    }
private:
    int num=0;
};


int main()
{
    Example e1;
    e1.print(5);
}

