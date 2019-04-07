#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;
using std::sort;


template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator cit = c.begin();
	while(cit != c.end()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

void test0()
{
	vector<int> numbers {5, 3, 7, 8, 2, 9, 1, 0};
	sort(numbers.begin(), numbers.end());
	display(numbers);
}
 
void test1()
{
	list<int> numbers {5, 3, 7, 8, 2, 9, 8, 1, 0};
	//sort(numbers.begin(), numbers.end());//error, sort要求使用随机访问迭代器
	numbers.sort();//其实现是归并排序,list自带sort
	display(numbers);

	auto it = numbers.begin();
	std::advance(it, 2);

	list<int> numbers2{10, 20, 30, 40, 50};
	auto it2 = numbers2.begin();
	std::advance(it2, 3);
	numbers.splice(it, numbers2, it2, numbers2.end()); // move elements from another list
	cout << "numbers:";
	display(numbers);

	cout << "numbers2:";
	cout << "number2's size() = " << numbers2.size() << endl;
	display(numbers2);

	numbers.unique();  //remove consective elements 去除相同元素
	cout << "numbers:";
	display(numbers);

}

int main(void)
{
	//test0();
	test1();
	return 0;
}
