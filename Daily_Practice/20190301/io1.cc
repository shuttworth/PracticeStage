#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;


//标准IO
void printcinstatus()
{
    cout<<"cin.badbit=="<<cin.bad()<<endl;
    cout<<"cin.failbit=="<<cin.fail()<<endl;
    cout<<"cin.eofbit=="<<cin.eof()<<endl;
    cout<<"cin.goodbit=="<<cin.good()<<endl;
}

int test0(void)
{   
    int number;
    while(cin>>number)
    {
        cout<<"number=="<<number<<endl;
    }//当正常输入数字的时候，打印number即可，
   // 非正常的时候，会跳出然后执行重置一系列操作
    cout<<"重置流的状态"<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    printcinstatus();
    string line;
    cin>>line;
    cout <<"line=="<<line<<endl;
    return 0;
}

void test1()
{
    int number;
    while(cin>>number,!cin.eof())
    {
        if(cin.bad())
        {
            cout <<"corrupted"<<endl;
            return;
        }else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"please input a number"<<endl;
            continue;
        }
        cout<<"number=="<<number<<endl;
    }
}

int main(void)
{
  // test0();
    test1();
    return  0;
}
