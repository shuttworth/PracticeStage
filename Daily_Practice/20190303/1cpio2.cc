#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;


vector<string> lines;
void test1()
{
    ifstream ifs("test1.txt");
    if(!ifs)
    {
        cout<<"ifstream error"<<endl;
    }

    lines.reserve(70);
    string hang;
    while(getline(ifs,hang))
    {
        lines.push_back(hang);
    }
    ifs.close();
}

void test2()
{
    test1();
    string file="test2.txt";
    ofstream ofs(file);
    if(!ofs)
    {
       cout<<" ofstream error"<<endl;
    }

    for(auto&elem:lines)
    {
        cout<<elem<<endl;
    }
}

int main()
{
    // test1();
    test2();
}
