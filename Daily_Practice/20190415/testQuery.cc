#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
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

void preprcessLine(string & str) //对Line 的引用，则在函数里直接对Line进行操作
{
    //作用：非字母变空格，大写转小写
    for(auto & ch : str)
    {
        if(!isalpha(ch))
        {
            ch = ' ';
        }else if(isupper(ch))
        {
            ch = tolower(ch);
        }
    }
}

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
            istringstream iss(line); //最开始的报错是没加头文件
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
        auto it = _dict.find(word);
        if(it!=_dict.end())
        {
            cout<<">> "<<word<<" occurs "<<it->second <<"  "<<((it->second >1)?"times":"time")<<endl; //三叶运算符判断单数还是复数
            auto & numbers = _word2Line[word];
            for(auto & number:numbers)
            {
                cout<<"  (line "<<(number + 1)<<" )"<<_file[number]<<endl;
            }
        }else
        cout<< "can not find in file" <<endl;
    }

private:
    vector<string> _file;
    map<string,int> _dict;
    map<string,set<int>> _word2Line;
};




int main()
{
    TextQuery tq;
    tq.read("china_daily.txt");

    cout<<"please input a word into query:"<<endl;
    string word;
    while(std::cin>>word)
    {
        preprcessLine(word);
        tq.query(word);
    }
    return 0;
}

