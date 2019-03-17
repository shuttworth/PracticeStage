#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void printstatus()
{
    cout<<"cin.badbit=="<<cin.bad()<<endl;
    cout<<"cin.failbit=="<<cin.fail()<<endl;
    cout<<"cin.eofbit=="<<cin.eof()<<endl;
    cout<<"cin.goodbit=="<<cin.good()<<endl;

}

void test0(){
    int number;
    while(cin>>number)
    {
        cout<<"number=="<<number<<endl;
    }
    cout<<"重置流的状态"<<endl;
    cin.clear();
    cin.ignore(1024,'\n');
    printstatus();
    string line;
    cin>>line;
    cout<<"line=="<<line<<endl;
}

void test1()
{
    int number;
    while(cin>>number,!cin.eof())
    {
        if(cin.bad())
        {
            cout<<"corrupted"<<endl;
            return ;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"please input an interger"<<endl;
            continue;
        }
        cout<<"number=="<<number<<endl;
    }
}


int main()
{
    test0();
   // test1();
}




