#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::map;
using std::set;
using std::string;

void preprcess(string & str)
{
	for(auto & ch : str) {
		if(!isalpha(ch)) {
			ch = ' ';
		} else if(isupper(ch)) {
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
		if(!ifs) {
			cout << "ifstream open " << filename << " error!" << endl;
			return;
		}
		
		string line;
		int count = 0;
		while(getline(ifs, line)) {
			_file.push_back(line);
			preprcess(line);
			string word;
			istringstream iss(line);
			while(iss >> word) {
				++_dict[word];
				_word2Line[word].insert(count);
			}
			++count;//处理下一行
		}
		ifs.close();
	}

	void query(const string & word)
	{
		auto it = _dict.find(word);
		if(it != _dict.end()) {
			cout << ">>> " << word << " occurs " << it->second << " " << ((it->second > 1)?"times": "time") << endl;
			auto & numbers = _word2Line[word];
			for(auto & number : numbers) {
				cout << "    (line " << (number + 1) << ") " << _file[number] << endl;
			}
		} else 
			cout << ">> " << word << " cannot find in file." << endl; 
	}

private:

private:
	vector<string> _file;
	map<string, int> _dict;
	map<string, set<int>> _word2Line;
};
 
int main(void)
{
	TextQuery tq;
	tq.read("china_daily.txt");

	cout << "pls input a word to query:" << endl;
	string word;
	while(std::cin >> word) {
		preprcess(word);
		tq.query(word);
	}
	return 0;
}
