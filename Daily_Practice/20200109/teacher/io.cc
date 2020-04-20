 ///
 /// @file    io.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-09 09:51:58
 ///
 
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

void test()
{
	ifstream ifs("log4cpp1.cc", std::ios::ate);
	if(!ifs.good()) {
		cerr << "ifstream open file error\n";
		return ;
	}

	//ifs.seekg(0, std::ios::end);
	size_t length = ifs.tellg();
	cout << "length:" << length << endl;

	ifs.seekg(std::ios::beg);
	//char buff[length + 1];
	char * buff = new char[length + 1]();
	ifs.read(buff, length);

	string file(buff);
	cout << "file:" << file << endl;


	ifs.close();
}

void test2()
{
	ifstream ifs("Point4.cc");//
	ifstream ifs2(ifs);//



}
 
int main(void)
{
	test();
	return 0;
}
