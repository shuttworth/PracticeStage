#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;
#if 0
输入element的打印效果
element occurs 125 times.
(line 62) element with a given key.
(line 64) second element with the same key.
(line 153) element |==| operator.
(line 250) the element type.
(line 398) corresponding element.
#endif

class TextQuery
{
public:
    void readFile(const string filename);
    void query(const string & word);
private:
    vector<string> lines;
    map<string, set<int> > wordNumbers;
    map<string, int> dict;
};


void TextQuery::readFile(const string filename)
{
    string name = filename;
    ifstream ifs(name);
    if(!ifs.good())
    {
        cerr<< "ifstream open file error\n"<<endl;
        return ;
    }
    lines.reserve(100);
    string linenow;
    size_t i=0;
    while(getline(ifs,linenow))
    {
        if(i<lines.size())
        {   
            lines[i]=linenow;
        }
        if(i==lines.size())//有无问题
        {
            lines.push_back(linenow);
        }
        ++i;
    }
    string wordnow;
    for(i=0;i<lines.size();++i)
    {
        istringstream is(lines[i]);
        while(is>>wordnow) //这里涉及的是字符串转换成单词,我猜要用到stringstream
        {
            wordNumbers[wordnow].insert(i);
            ++dict[wordnow];
        }
    }
    cout<<"记录已完毕"<<endl;
}


void TextQuery::query(const string & word)
{
    cout<<word<<"---->"<<" occurs "<<dict[word]<<" times";
    cout<<endl;
    //int i=0;
   // for(i=0;i<dict[word];++i)
   // {
        set<int> s1=wordNumbers[word];
        for(set<int>::iterator it=s1.begin();it!=s1.end();++it)
        {
            cout<<"   (line "<<*it<<")"
                <<lines[*it]<<endl;
        }

   // }
}


//   程序测试用例
int main()
{
    string  queryWord("the");

    TextQuery tq;
    tq.readFile("china_daily.txt");
    tq.query(queryWord);            
    return 0;
};
