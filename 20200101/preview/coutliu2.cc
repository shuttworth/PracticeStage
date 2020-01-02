#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n=141;
    cout<<"1) " <<hex<<n<<"  "<<dec<<n<<"  "<<oct<<n <<endl;
    double x = 1234567.89,y=12.34567;
    cout<<"2) "<<setprecision(5)<<x<<"  "<<y<<"  "<<endl;
    cout<<"3) "<<fixed<<setprecision(5)<<x<<"  "<<y<<endl;
    //setprecision(n)	设置输出浮点数的精度为 n。
    //在使用非 fixed 且非 scientific 方式输出的情况下，n 即为有效数字最多的位数，如果有效数字位数超过 n，则小数部分四舍五人，或自动变为科学计 数法输出并保留一共 n 位有效数字。
   //在使用 fixed 方式和 scientific 方式输出的情况下，n 是小数点后面应保留的位数。
    
    cout<<"4) "<<scientific<<setprecision(5)<<x<<"  "<<y<<endl;
    //科学计数法，设置精度，自然是小数点后五位
    

    return 0;
}

