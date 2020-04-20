#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
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
    /* cout<<"ifs.badbit: "<<ifs.bad()<<endl; */
    /* cout<<"ifs.failbit: "<<ifs.fail()<<endl; */
    /* cout<<"ifs.eofbit: "<<ifs.eof()<<endl; */
    /* cout<<"ifs.goodbit: "<<ifs.good()<<endl; */

    string wordnow;
    while(ifs>>wordnow)
    {
        if(wordnow[0]>='0'&&wordnow[0]<='9')
        {
            continue; //继续从下一个while开始执行
        }
        /* cout<<wordnow<<endl; */
        /* sleep(1); */ // right here
        size_t vsize =word.size();
        size_t i=0;
        //cout<< vsize<<endl; all 0000000
        for(i=0;i<vsize;i++)
        {
            if((word[i].compare(wordnow))==0)
            {
                count[i]++;
                break;
            }
            // cout<<word[i]<<count[i]<<endl;
        }

        if(i==vsize)
        {
            word.push_back(wordnow); //猜测是没有保存成功
            count.push_back(1);

        }
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

    size_t size = word.size();
    for(size_t i=0;i<size;i++)
    {
        ofs<<word[i]<<"   "<<count[i]<<'\n';
    }
    ofs.close();
    cerr<<"词典已经写好"<<endl;
}




int main()
{
    double start=time(NULL);
    Dictionary d1;
    d1.read("The_Holy_Bible.txt");
    d1.store("Dictionary.txt");
    double end=time(NULL);
    cout<<"TOTAL TIME="<<(int)(end-start)<<"s"<<endl;
    return 0;
}

