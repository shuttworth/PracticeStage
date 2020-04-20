#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#define MAXKEY 10000
int _hash(const char * key)
{
    int h=0,g;
    while(*key)
    {
        h = (h << 4) + *key++;
        g = h & 0xf0000000;
        if (g)
            h ^= g >> 24;
        h &= ~g;

    }
    return h% MAXKEY;
}


typedef struct sta{
    int count;
    string word;
}sta;  //存读取信息的结构图


class Dictionary{
public:
    void read(const string &readname);
    void  store(const string &dictname);
private:
    char *_readname;
    char *_dictname;
}; //词典类


sta * data=new sta[MAXKEY](); //开辟sta结构图一个十万大小的空间

void Dictionary::read(const string & readname)
{
    ifstream ifs(readname);
    if(!ifs)
    {
        cerr<<"open ifstream"<<readname<<" error"<<endl;
        return;
    }
    int index ,i;
    string alp;
    string line;
    while(ifs>>alp)
    {
        if(alp[0]>='0'&&alp[0]<='9')
        {
            continue;
        }
        index = _hash(alp.c_str());//由哈希函数得到下标
        if(data[index].count==0) //此处未存放，则存放哈希后的值
        {
            data[index].word=alp;
            ++data[index].count;
        }else{//此处存放了，则线性探测再散列法
            i=0;
            while(data[(index+i)%MAXKEY].word.compare(alp)==true)
            {//同一个word的count必须累加在一起
                i++;
            }
            if(!data[(index+i)%MAXKEY].count)
                data[(index+1)%MAXKEY].word=alp;
            data[(index+1)%MAXKEY].count++;
        }
    }
}




void Dictionary::store(const string & dictname )
 {
     string name =dictname;
     ofstream ofs(name);
     if(!ofs.good())
     {
         cerr<<"ofstream create file error\n"<<endl;
         return ;
     }
     for(int i=0;i<MAXKEY;++i)
     {
         if(data[i].count>0)
             ofs<<data[i].word<<"    "<<data[i].count<<"\n";
     }
     cout<<"统计单词结束"<<endl;
 }





int main()
{
    double start=clock();
    Dictionary d1;
    d1.read("The_Holy_Bible.txt");
    d1.store("hash.txt");
    double end=clock();
    cerr<<"TOTALTIME"<<(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}

