#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

void test()
{
    int number =0;
    cout<<"pls input a valid integer:\n";

    while(cin>>number ,!cin.eof())
    {
        if(cin.bad())
        {
            cerr <<"stream has corupted! \n";
            return;
        }

        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"pls input a valid integer:\n"<<endl;
            continue;
        }

        cout<<"number = " <<number<<endl;
    }
}

int main()
{
    test();
    return 0;
}

