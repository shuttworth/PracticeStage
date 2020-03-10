#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>

using namespace std;

class TextQuery
{
public:
    void readFile(const string filename);
    void query(const string & word);
private:
    vector<string> lines;
    //map<string, set<int> > wordNumbers;
    map<string, shared_ptr<set<int> >> wordNumbers;
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
            auto & lines_ptr = wordNumbers[wordnow];
            if(!lines_ptr)
            {
                lines_ptr.reset(new set<int>);
            }
            lines_ptr->insert(i);
           // wordNumbers[wordnow].insert(i);
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
           for( auto & num :*wordNumbers[word]){
        //set<int> s1=wordNumbers[word]; //这里其实是拷贝,想要通过shared_ptr实现不拷贝
        /* for(set<int>::iterator it=(lines_ptr->begin());it!=lines_ptr->end();++it) */
        /* { */
        /*     cout<<"   (line "<<*it<<")" */
        /*         <<lines[*it]<<endl; */
        /* } */
        cout<<"   (line "<<num+1<<") ";
           cout<< lines[num]<<endl;
   }
}


//   程序测试用例
int main(/*int agrc,char * argv[]*/)
{
    string  queryWord("the");

    TextQuery tq;
    tq.readFile("china_daily.txt");
   // tq.readFile(argv[1]);
    tq.query(queryWord);            
   // cout<<argv[2]<<endl;
    return 0;
};
