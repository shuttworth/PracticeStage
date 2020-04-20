#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{

public:
    void setBrand(const char * brand){ //strcpy第二个函数要求是const char * 格式的
        strcpy(_brand,brand);
    }

    void setPrice(int price){
       _price=price;
    }

    void print(){
        cout<<"_brand="<<_brand<<endl;
        cout<<"_price="<<_price<<endl;
    }

protected:
    int _price;

private:
    char  _brand[20]; //为何这里不可以直接char * _brand
};

int main()
{
    Computer pc1;
    pc1.setBrand("HUAWEI");
    pc1.setPrice(3999);
    pc1.print();
    return 0;
}

