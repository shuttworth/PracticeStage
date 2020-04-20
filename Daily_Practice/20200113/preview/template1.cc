#include <iostream>
using namespace std;

//声明函数模板
template<typename T> T max(T a, T b, T c);

int main( ){
    //求三个整数的最大值
    int i1, i2, i3, i_max;
    cin >> i1 >> i2 >> i3;
    i_max = max(i1,i2,i3);
    cout << "i_max=" << i_max << endl;

    //求三个浮点数的最大值
    double d1, d2, d3, d_max;
    cin >> d1 >> d2 >> d3;
    d_max = max(d1,d2,d3);
    cout << "d_max=" << d_max << endl;

    //求三个长整型数的最大值
    long g1, g2, g3, g_max;
    cin >> g1 >> g2 >> g3;
    g_max = max(g1,g2,g3);
    cout << "g_max=" << g_max << endl;

    return 0;
}

//定义函数模板
template<typename T>  //模板头，这里不能有分号
T max(T a, T b, T c){ //函数头
    T max_num = a;
    if(b > max_num) max_num = b;
    if(c > max_num) max_num = c;
    return max_num;
}
