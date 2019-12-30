#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
private:
    char *_brand;
    float _price;

public:
    Computer(const char * brand,float price)
    :_brand(new char [strlen(brand)+1])
    ,_price(price)
    {
        strcpy(_brand,brand);
        cout<<"Computer(const char * brand,float price)"<<endl;
    }

    ~Computer()
    {
        delete [] _brand; //[]为什么要这么操作
        cout<<"~Computer()"<<endl;
    }

    void print(){
        cout<<"brand="<<_brand<<endl;
        cout<<"price="<<_price<<endl;
    }

};

void test0()
{
    Computer c1("apple",16000);
    c1.print();
}

void test1()
{
    Computer * p1=new Computer("xiaomi",6666);
    p1->print();
    delete p1;
}


int main()
{
    //test0();
    test1();
    return 0;
}

