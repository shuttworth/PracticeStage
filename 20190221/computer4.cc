#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
private:
    char * _brand;
    float _price;


public:
    Computer(const char* brand,float price)
    :_brand(new char[strlen(brand)+1]())
    ,_price(price)
    {
        strcpy(_brand,brand);
        cout<<"Computer(const char* brand,float price)"<<endl;
    }

    ~Computer()
    {
        delete [] _brand;
        cout<<"~Computer()"<<endl;
    }

    void print()
    {
        cout<<"品牌："<<_brand<<endl
            <<"价格："<<_price<<endl;
    }
};


int test0(void)
{
    cout<<"int test0(void)"<<endl;
    Computer c1("xiaomi",7777);
    c1.print();
    return 0;

}

int main()
{
    Computer * p1=new Computer("zhanshen",9999);
    p1->print();
    delete p1;
    test0();
    return 0;
}

