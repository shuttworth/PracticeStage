#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::fstream;


vector<string> lines;

void test1()
{
    ifstream fs1("test1.txt");
    if(!fs1.good())
    {
        cout<<"ifstream create error"<<endl;
    }

    lines.reserve(70);
    string hang;
    /*
    while(std::getline(fs1,hang))
    {
        lines.push_back(hang);
    }
    */

    for(auto & elem: lines)//仅用于C++ 11以后的版本，编译需要加上-std=c++11
    {
        cout<<elem<<endl;

    }
    fs1.close();
}


void test2()
{
    test1();
    string file="test2.txt";
    ofstream ofs(file);
    if(!ofs)
    {
        cout<<"ofstream error"<<endl;
    }

    for(auto&elem:lines)
    {
        cout<<elem<<endl;
    }
}

void test3()
{
    ofstream ofs("test2.txt",std::ios::app);//实现在文件的末尾继续写数据
    if(!ofs)
    {
        cout <<"ofstream error"<<endl;
    }
    int pos=ofs.tellp();
    cout <<"pos=="<<pos<<endl;
    // "hello">>ofs;
   // ofs<<"hello";
    ofs.close();

}

void test4()
{
    fstream fst("test2.txt");//指针默认停在开头处，这样txt原本的内容会被覆盖
    if(!fst)
    {
        cout<<"fstream create error"<<endl;
    }
    cout <<"please input 10 numbers"<<endl;
    int number,idx;
    for(idx=0;idx!=10;idx++)
    {
        // number<<cin;
        cin>>number;
        fst<<number;
        fst<<'\n';
    }//已经往文件里写好了
    int pos=fst.tellp();
    cout <<"pos=="<<pos<<endl;
    fst.seekg(0,std::ios::beg);
    cout <<"fst.badbit=="<<fst.bad()<<endl;
    cout <<"fst.failbit=="<<fst.fail()<<endl;
    cout<< "fst.eofbit=="<<fst.eof()<<endl;
    cout<<"fst.goodbit=="<<fst.good()<<endl;

    for(idx=0;idx!=10;idx++)
    {
        fst>>number;
        cout<<endl;
        cout <<"fst.badbit=="<<fst.bad()<<endl;//打印监测信息very neccessary
        cout <<"fst.failbit=="<<fst.fail()<<endl;
        cout<< "fst.eofbit=="<<fst.eof()<<endl;
        cout<<"fst.goodbit=="<<fst.good()<<endl;
        cout<<number;
    }//从文件里读出来
    cout<<endl;

    fst.close();

}


int main(void)
{
    // test1();
    // test2();
    // test3();
   test4();
}




