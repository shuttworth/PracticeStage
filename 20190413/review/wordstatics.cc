#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <time.h>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::sort;
struct Record
{
    string word;
    int freq;
};

bool operator < (const Record & lhs,const Record & rhs)
{
    return lhs.freq>rhs.freq;
}


class wordstatics
{
private:
    // vector<string>_words;//词和词频分开不好,所以用一个结构体同时存储信息
    // vector<int>_freqs;
    vector<Record>_dictionary;


public:
    void read(const string & filename)
    {
        ifstream ifs(filename);
        if(!ifs.good())
        {
            cout<<"ifstream open "<<filename<<" error"<<endl;
            return ;
        }
        time_t beg=::time(NULL);
        string line;
        while(getline(ifs,line))//每次读一行
        {
            istringstream iss(line); //每次把line中的东西存入iss流中
            string preword;
            while(iss>>preword) //每次读取一个单词
            {
                string word=processWord(preword);//及时封装成一个函数,处理读取到的东西
                if(word!=string()) //如果不是空串
                {
                    size_t idx=0; //vector数组的下标是size_t 类型的
                    for(;idx!=_dictionary.size();++idx)
                    {
                        if(_dictionary[idx].word==word)
                        {
                            _dictionary[idx].freq++;
                            break;
                        }

                    }

                    //没有在字典中发现单词
                    if(idx==_dictionary.size())
                    {
                        Record record;
                        record.word=word;
                        record.freq=1;
                        _dictionary.push_back(record);//加入vector数组
                    }
                }

            }
        }
        ifs.close();
        //加上对统计结果的排序
        //
        sort(_dictionary.begin(),_dictionary.end());
        time_t end=::time(NULL);
        cout<<"processTime=="<<end-beg<<endl;
    }

    void store(const string & filename)
    {
        ofstream ofs(filename);
        if(!ofs.good())
        {
            cout<<"ofstream create "<<filename<<" error"<<endl;
            return ;
        }

        for(auto & record : _dictionary)  //借助迭代器实现record从_dictionary里循环读出来内容
        {
            ofs<<record.word<<"  "<<record.freq<<"\n ";
        }
    }

private:
    string processWord(const string & preword)
    {
        for(auto&ch:preword)
        {
            if(!isalpha(ch))  //如果不是英文字母
            {
                return string();//返回一个空串
            }
        }
        return preword;
    }
};



int main()
{
    wordstatics ws;
    ws.read("The_Holy_Bible.txt");
    ws.store("dict.txt");
    return 0;
}
