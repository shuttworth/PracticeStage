#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class computer
{
public :
    void setBrand(const char* brand )
        {
            strcpy(_brand,brand);
            cout << "_brand is " << _brand <<endl;
        }
        void setPrice(int price)
        {
            _price=price;
            cout << "_price is " << _price <<endl;
        }
protected:float _price;
private:char _brand[20];
};

int main()
{
    computer cp1;
    cp1.setBrand("lenove");
    cp1.setPrice(5500);
    return 0;
}

