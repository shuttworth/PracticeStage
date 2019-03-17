#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::ifstream;


void test0()
{
    int n1=100,n2=200;
    stringstream ss;
    ss<<"n1="<<n1<<" n2="<<n2;//
    string line=ss.str();//str接口
    cout<<line<<endl;
                        //字符串的写和反写
    string word;
    int number;
    while(ss>>word>>number,!ss.eof())
    {
        cout<<word<<"  "<<number<<'\n';
    }
    cout<<endl;
}

string int2str(int number)//把一个int型的转换成字符串
{
    ostringstream oss;
    oss<<number;
    return oss.str();//string 类型的，返回str（）
}

void readConfig(const string & file)
{
    ifstream ifs(file);
    if(!ifs)
    {
        cout<<"ifstream create error"<<endl;
    }
    string key,value;
    string line;
    while(getline(ifs,line))
    {
        istringstream iss(line);//天然有空格分割
        iss>>key>>value;
        cout<<key<<"->"<<value<<endl;
    }
    ifs.close();
}






int main()
{
   // test0();
   cout << int2str(1024)<<endl;
   cout<<std::to_string(1024)<<endl;

   readConfig("server.conf");
   return 0;
}

