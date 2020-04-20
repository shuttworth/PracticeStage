#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
 
int main(void)
{
	vector<int> numbers;
	istream_iterator<int> isi(cin);//开始读取数据 cin >> _M_value 可读源码

	//std::copy(isi, istream_iterator<int>(), numbers.begin());//添加新元素
	//std::back_inserter返回的是一个std::back_insert_iterator尾部插入迭代器
	std::copy(isi, istream_iterator<int>(), std::back_inserter(numbers));//添加新元素

	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, "\n"));

	return 0;
}
