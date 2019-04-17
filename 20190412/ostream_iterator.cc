#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::copy;
 
int main(void)
{
	vector<int> numbers{3, 2, 1, 4, 5, 6};

	//把cout当成一个容器看待
	//输出流迭代器执行的是写操作
	//
	//迭代器适配器
	//
	ostream_iterator<int> osi(cout, " ");

	copy(numbers.begin(), numbers.end(), osi);
    
	return 0;
}
