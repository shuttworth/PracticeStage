#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

void test0()
{
	float number = 1.11;
	ostringstream oss;
	oss << number;
	string str = oss.str();
	cout << "str:" << str << endl;
}

void readConfigFile(const string & name)
{
	ifstream ifs(name);
	if(!ifs) {
		cerr << "ifstream open " << name << " error\n";
		return;
	}

	string key, value;
	string line;
	while(getline(ifs, line)) {
		istringstream iss(line);//没有close方法, 不需要关闭
		iss >> key >> value;
		cout << key << " --> " << value << endl;
	}
}
 
int main(void)
{
	test0();
	readConfigFile("my.conf");

	return 0;
}
