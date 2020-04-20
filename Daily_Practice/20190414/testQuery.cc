#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::map;
using std::set;
using std::string;
using std::vector;


class TextQuery
{
public:
    void read(const string & filename)
    {
        ifstream ifs(filename);
        if(!ifs)
        {
            cout<<"ifstream open "<<filename<<"error"<<endl;
            return;
        }

        string line;
        int count=0;
        while(getline(ifs,line))
        {
            _file.push_back(line);
            preprcessLine(line);
            string word;
            istringstream iss(line);
            while(iss>>word)
            {
                ++_dict[word];
                _word2Line[word].insert(count);
            }
            ++count; //处理下一行
        }
        ifs.close();
    }

    void query(const string & word)
    {
        auto it = 
    }
private:
    void preprcessLine(string & line) //对Line 的引用，则在函数里直接对Line进行操作
    {
        for(auto & ch : line)
        {
            if(!isalpha(ch))
            {
                ch = '  ';
            }else if(isupper(ch))
            {
                ch = tolower(ch);
            }
        }
    }

private:
    vector<string> _file;
    map<string,int> _dict;
    map<string,set<int>> _word2Line;
};




int main()
{
    return 0;
}

