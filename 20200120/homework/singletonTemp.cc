#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Point;
class Computer;


template<class T>
class Singleton
{
public:
    static Singleton<T> * getInstance();

private:
    void destroy();

private:
    Singleton<T>();
    ~Singleton<T>();
    static Singleton<T> * _pstr;
};



//Point pt(1, 2);
//Point pt2(3, 4);

//Computer com("Mac", 8888);


int main(void)
{
    /* Computer * p1 = Singleton<Computer>::getInstance("Xiaomi", 6666); */
    /* Computer * p2 = Singleton<Computer>::getInstance("Xiaomi", 6666); */

    /* Point　* p3 = Singleton<Point>::getInstance(1, 2); */
    /* Point　* p4 = Singleton<Point>::getInstance(1, 2); */

    return 0;
}
