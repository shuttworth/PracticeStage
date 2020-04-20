 ///
 /// @file    Dictionary.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 09:54:02
 ///
 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;
using std::ifstream;
using std::ofstream;

struct Record
{
	Record(int freq, const string & word)
	: _freq(freq)
	, _word(word)
	{}

	int _freq;
	string _word;
};

bool operator<(const Record & lhs, const Record & rhs)
{
	return lhs._word < rhs._word;
}

class Dictionary
{
public:
	Dictionary(int size = 1000)
	{
		_dict.reserve(size);
	}

	void read(const string & filename);
	void store(const string & filename);
private:
	string preprocess(const string & word);
	void statistic(const string & word);

private:
	vector<Record> _dict;
};

//一个函数最多不要超过50行
void Dictionary::read(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		std::cerr << ">> ifstream open file "
			      << filename << " error\n";
		return ;
	}

	string word;
	string line;
	//while(ifs >> word, !ifs.eof()) {
	//每一次处理一行
	while(getline(ifs, line), !ifs.eof()) {
		istringstream iss(line);	
		while(iss >> word) {
			//对单词进行预处理操作
			string processWord = preprocess(word);
			//对单词进行统计操作
			statistic(processWord);
		}
	}

	//考虑排序
	std::sort(_dict.begin(), _dict.end());

	ifs.close();
}


string Dictionary::preprocess(const string & word)
{
	for(size_t idx = 0; idx != word.size(); ++idx) {
		if(!isalpha(word[idx])) {
			return string();	
		}
	}
	return word;
}

void Dictionary::statistic(const string & word)
{
	if(word == string())
		return;

	for(auto & record : _dict) {
		if(record._word == word) {
			++record._freq;
			return;
		}
	}

	_dict.push_back(Record(1, word));
}

void Dictionary::store(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs) {
		std::cerr << ">> ofstream open file " << filename << " error\n";
		return;
	}

	for(auto & record : _dict) {
		ofs << record._word << " " << record._freq << "\n";
	}

	ofs.close();
}


 
int main(int argc, char *argv[])
{
	Dictionary dict;
	dict.read(argv[1]);
	dict.store(argv[2]);

	//Record re1, re2;
	//re1 < re2;
	return 0;
}
