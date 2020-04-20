 ///
 /// @file    fileIO1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 15:57:00
 ///
 

#include <string.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

vector<string> file;

void test0()
{
	//文件流必须要求文件存在
	ifstream ifs("fileIO1.cc");
	if(!ifs.good()) {
		cerr << "ifstream open file error!\n";
		return ;
	}

	string word;
	//while(ifs >> word)//默认情况下以空格作为分隔符
	//char buff[128] = {0};
	//while(ifs.getline(buff, 128)) {
	string line;

	while(getline(ifs, line)) {
		file.push_back(line);
		cout << "pos: " << ifs.tellg() << endl;
	}

#if 0
	for(auto & line:file) {
		cout << line << endl;
	}
#endif

	ifs.close();//关闭文件流对象
}

void test1()
{
	//文件输出流
	//	 当文件不存在时，直接创建新文件
	//	 当文件存在时，默认情况下会直接清空文件流的内容
	string name("test.txt");
	ofstream ofs(name);
	if(!ofs.good()) {
		cerr << "ofstream open file error\n";
		return ;
	}

#if 0
	for(auto & line : file) {
		ofs << line << "\n";
	}
#endif

	ofs.close();//关闭文件输出流
}

int main(void)
{
	test0();
	//test1();
	return 0;
}
