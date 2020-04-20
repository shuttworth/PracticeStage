#include <iostream>
using namespace std;
int main()
{
    char szBuf[20];
    int n = 120;
    if(!cin.getline(szBuf,6))  //如果输入流中一行字符超过5个，就会出错
        cout << "error" << endl;
    cout << szBuf << endl;
    cin >> n;
    cout << n  << endl;
    cin.clear(); //clear能够清除cin内部的错误标记，使之恢复正常
    cin >> n;
    cout << n << endl;
    return 0;
}

/*在上面的输入情况下，程序是正常的。程序运行过程中还可能出现如下情况：
ab cd123456k↙
error
ab cd
120
123456

第 7 行，读入时因字符串超长导致出错，于是第 11 行并没有从输入流读入 n，n 维持了原来的值 120。

第 12 行，调用 istream 的成员函数 clear() 清除 cin 内部的错误标记，此后 cin 又能正常读入了。因此，123456 在第 13 行被读入 n。
*/
