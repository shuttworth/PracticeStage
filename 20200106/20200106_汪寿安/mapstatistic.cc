#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <map>
#include <iomanip>
//#include <ofstream>
using namespace std;
/* using std::cout; */
/* using std::cin; */
/* using std::endl; */
/* using std::string; */
/* using std::vector; */
/* using std::ifstream; */


class Dictionary
{
public:
    //......
    void read(const string & filename);
    void store(const string & filename);
private:

    vector<string> word;
    vector<int>count; 
};
/* void print() */
/* { */
/*     cout<<"cin.badbit: "<<cin.bad()<<endl; */
/*     cout<<"cin.failbit: "<<cin.fail()<<endl; */
/*     cout<<"cin.eofbit: "<<cin.eof()<<endl; */
/*     cout<<"cin.goodbit: "<<cin.good()<<endl; */
/* } */
map<string,int> mp;


void Dictionary::read(const string & filename)
{
    string name = filename;
    ifstream ifs(name);
    // cout<<name<<endl;
    if(!ifs.good())
    {
        cerr<< "ifstream open file error\n"<<endl;
        return ;
    }
    string wordnow;
    while(ifs>>wordnow)
    {
        if(wordnow[0]>='0'&&wordnow[0]<='9')
        {
            continue;
        }

        mp[wordnow]++;
    }

    ifs.close();
    cerr<<"统计已经结束"<<endl;

    /* for(size_t i=0;i<word.size();i++) */
    /* { */
    /*     cout<<word[i]<<endl; */
    /* } */
}


void Dictionary::store(const string & filename)
{
    string name = filename;
    //cout<<name<<endl;
    ofstream ofs(name);
    if(!ofs.good())
    {
        cerr<< "ofstream create file error\n"<<endl;
        return ;
    }

    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        ofs<<it->first<<setw(10)<<it->second<<endl;
    }

    ofs.close();
    cerr<<"词典已经写好"<<endl;
}




int main()
{
    double start=clock();
    Dictionary d1;
    d1.read("The_Holy_Bible.txt");
    d1.store("mapDictionary.txt");
    double end=clock();
    cout<<"TOTAL TIME="<<(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}

