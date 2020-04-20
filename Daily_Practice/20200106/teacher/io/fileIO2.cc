 ///
 /// @file    fileIO2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 17:19:24
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::fstream;
using std::ofstream;

void test0()
{
	ofstream ofs("test.txt", std::ios::app);
	if(!ofs) {
		cerr << "ofstream open error\n";
		return;
	}
	//
	//获取当前文件流对象的位置
	size_t pos = ofs.tellp();
	cout << "pos:" << pos << endl;

	ofs << "this is a new line\n";


	ofs.close();
}

void printStreamState(fstream & fs)
{
	cout << "fs.badbit : " << fs.bad() << endl;
	cout << "fs.failbit: " << fs.fail() << endl;
	cout << "fs.eofbit: " << fs.eof() << endl;
	cout << "fs.goodbit: " << fs.good() << endl << endl;
}

void test1()
{
	int number = 0;

	fstream fs("test.dat");
	if(!fs) {
		cerr << "fstream open file error\n";
		return ;
	}

	for(size_t idx = 0; idx != 5; ++idx) {
		cin >> number;
		fs << number << " ";
	}
	cout << "fs.pos: " << fs.tellg() << endl;

	number = 100;
	printStreamState(fs);
	fs.seekg(std::ios::beg);//偏移文件游标的位置

	for(size_t idx = 0; idx != 5; ++idx) {
		fs >> number;
		//printStreamState(fs);
		cout << number << ",";
	}
	cout << endl;
}

 
int main(void)
{
	//test0();
	test1();
	return 0;
}
