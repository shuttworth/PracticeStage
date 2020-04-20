#include <time.h>
#include <string.h>

//用map实现词频统计

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::istringstream;

#if 0
struct Record
{
	string word;
	int freq;
};

bool operator<(const Record & lhs, const Record & rhs) {
	return lhs.freq > rhs.freq;
}
#endif

class WordStatics
{
public:
	void read(const string & filename)
	{
		ifstream ifs(filename);
		if(!ifs.good()) {
			cout << "ifstream open " << filename << " error!" << endl;
			return;
		}
	
		clock_t beg = ::clock();
		
		string line;
		while(getline(ifs, line)) {
			istringstream iss(line);
			string preword;
			while(iss >> preword) {
				//cout << "preword: " << preword << endl;
				string word = processWord(preword);
				if(word != string()) {
					++_dictionary[word];
#if 0
					auto it = _dictionary.find(word);
					if(it != _dictionary.end())
						++_dictionary[word];
					else 
						_dictionary.insert(std::make_pair(word, 1));
#endif
				}
			}
		}
		ifs.close();
		clock_t end = ::clock();

		cout << "process time： " << (end - beg) << "CPU time" << endl;
	}
	
	void store(const string & filename)
	{
		ofstream ofs(filename);
		if(!ofs.good()) {
			cout << "ofstream create " << filename << " error" << endl;
			return;
		}

		for(auto & record : _dictionary) {
			ofs << record.first << " " << record.second << "\n";
		}

		ofs.close();
	}
private:
	string processWord(const string & preword)
	{
		for(auto & ch : preword) {
			if(!isalpha(ch)) {
				return string();
			}
		}
		return preword;
	}

private:
	//vector<Record> _dictionary;
	//map<string, int> _dictionary;
	unordered_map<string, int> _dictionary; //unordered_map 乱序形式，速度很快
};
 
int main(void)
{
	WordStatics ws;
	ws.read("The_Holy_Bible.txt");
	ws.store("dict.txt");
	return 0;
}
