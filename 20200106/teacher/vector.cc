 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-06 16:26:56
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

char buff[128] = {0};

void printCapacity(const vector<int> & c)
{
	//size 表示的是当前容器中元素的个数
	cout << "c.size: " << c.size() << endl
	//capacity 表示当前容器中可以容纳元素的个数
		 << "c.capacity: " << c.capacity() << endl;
}

void test0()
{
	//动态数组, 可以动态扩容:
	//实现原理: 当size() == capacity()，此时
	//还要再添加新的元素，执行动态扩容：
	//  先申请新空间  2 * capacity(), 
	//  然后将原来空间的数据复制到新空间中去，
	//  再回收原来的空间
	//  最后再新空间上添加新元素
	vector<int> numbers;
	numbers.reserve(100);

	printCapacity(numbers);

	numbers.push_back(1);
	printCapacity(numbers);

	numbers.push_back(1);
	printCapacity(numbers);
	
	numbers.push_back(1);
	printCapacity(numbers);

	numbers.push_back(1);
	printCapacity(numbers);

	numbers.push_back(1);
	printCapacity(numbers);

	for(auto & number : numbers) {
		cout << number << " ";
	}
	cout << endl;

	for(size_t idx = 0; idx != numbers.size(); ++idx) {
		cout << numbers[idx] << " ";
	}
	cout << endl;
}
 
int main(void)
{
	test0();

	return 0;
}
