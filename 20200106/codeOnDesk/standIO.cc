#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void print()
{
    cout<<"cin.badbit: "<<cin.bad()<<endl;
    cout<<"cin.failbit: "<<cin.fail()<<endl;
    cout<<"cin.eofbit: "<<cin.eof()<<endl;
    cout<<"cin.goodbit: "<<cin.good()<<endl;
}




int main()
{
    int number =0 ;
    print();
    cin>>number;
    print();
    cout<<"number = "<<number<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<endl;
    print();


    cout<<endl;
    string line;
    cin>>line;
    cout<<"line : "<<line<<endl;







    return 0;
}

