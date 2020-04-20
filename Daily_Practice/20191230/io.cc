#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printstatus()
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
        cout<<"number == "<<number<<endl;
    }

    cout<<"reset"<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    printstatus();

}



int main()
{
    return 0;
}

