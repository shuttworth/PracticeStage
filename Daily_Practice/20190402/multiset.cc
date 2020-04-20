#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::multiset;

template <typename Container>
void display(const Container & c)
{
	for(auto & elem : c) {
		cout << elem << " ";
	}
	cout << endl;
}

void test0()
{
	//multiset之中能存放关键字相同的元素, 默认情况下按升序排列
	int arr[10] = {4, 4, 2, 3, 2, 1, 5, 6, 2, 1};
	multiset<int> numbers(arr, arr + 10);
	display(numbers);

	//cout << numbers[0];//multiset不支持下标访问运算符
	
	//查找
	size_t cnt = numbers.count(1);
	cout << "1 cnt = " << cnt << endl;
	cnt = numbers.count(7);
	cout << "7 cnt = " << cnt << endl;

	multiset<int>::iterator it = numbers.find(1);
	cout << "*it = " << *it << endl;
	
    //范围查找
	auto lit = numbers.lower_bound(2); //下沿
	auto uit = numbers.upper_bound(2); //上沿
	for(; lit != uit; ++lit) {
		cout << *lit << " ";
	}
	
    cout << endl;
	cout << "*uit = " << *uit << endl;
	cout << endl << ">> test equal_range()" << endl;
	auto ret = numbers.equal_range(2); //返回值是pair类型，迭代器的范围
	lit = ret.first; uit = ret.second;
	for(; lit != uit; ++lit) {
		cout << *lit << " ";
	}
	cout << endl;
	cout << "*uit = " << *uit << endl;
}

void test1()
{
	int arr[10] = {4, 4, 2, 3, 2, 1, 5, 6, 2, 1};
	multiset<int, std::greater<int>> numbers(arr, arr + 10);
	display(numbers);

	//cout << numbers[0];//set不支持下标访问运算符
	
	//查找
	size_t cnt = numbers.count(1);
	cout << "cnt = " << cnt << endl;
	cnt = numbers.count(7);
	cout << "cnt = " << cnt << endl;

	multiset<int, std::greater<int>>::iterator it = numbers.find(1);
	cout << "*it = " << *it << endl;

	if(numbers.find(7) == numbers.end())
	{
		cout << "7 不存在" << endl;
	}

	//添加元素
	multiset<int>::iterator mit = numbers.insert(7);
	cout << *mit << endl;
	
	int arr2[3] = {7, 8, 9};
	numbers.insert(arr2, arr2 + 3);
	display(numbers);
}

int main(void)
{
	test0();
	//test1();
	return 0;
}
