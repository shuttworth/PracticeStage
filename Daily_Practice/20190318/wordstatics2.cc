#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <algorithm>



using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::sort;
using std::vector;

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
    vector<Record>_dictionary;

public:
    void read(const string & filename)
    {
        ifstream ifs(filename);
        if(!ifs.good())
        {
            cout<<"ifstream create error "<<filename<<endl;
            return ;
        }
        time_t beg=::time(NULL);
        string line;
        while(getline(ifs,line))
        {
            istringstream iss(line);
            string preword;
            while(iss>>preword)
            {
                string word=processWord(preword);
                if(word!=string())
                {
                    size_t idx=0;
                    for(;idx!=_dictionary.size();idx++)
                    {
                        if(_dictionary[idx].word==word)
                        {
                            _dictionary[idx].freq++;
                            break;
                        }
                    }

                    if(idx==_dictionary.size())
                    {
                        Record record;
                        record.word=word;
                        record.freq=1;
                        _dictionary.push_back(record);
                    }
                }
            }

        }
        ifs.close();

        sort(_dictionary.begin(),_dictionary.end());
        time_t end=::time(NULL);
        cout<<"processTime=="<<end-beg<<endl;
    }






    void store(const string & filename)
    {
        ofstream ofs(filename);
        if(!ofs.good())
        {
            cout<<"ofstream error "<<filename<<endl;
            return ;
        }

        for(auto& record:_dictionary)
        {
            ofs<<record.word<<"  "<<record.freq<<endl;
        }
    }



private:
    string processWord(const string & preword)
    {
        for(auto& ch:preword)
        {
            if(!isalpha(ch))
            {
                return string();
            }
        }
            return preword;
    }
};

int main()
{
    wordstatics ws;
    ws.read("The_Holy_Bible.txt");
    ws.store("dict2.txt");
    return 0;
}

