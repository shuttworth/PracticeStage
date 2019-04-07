#include <iostream>
#include <utility>
#include <string>
using std::cout;
using std::endl;
using std::pair;
using std::string;

void test0()
{
	pair<string, int> t("hello", 10);

	cout << t.first << " --> " << t.second << endl;
}
 
int main(void)
{
	test0();
	return 0;
}
