#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::binary_search;
using std::vector;
using std::list;
using std::sort;
 
int test0(void)
{
	vector<int> numbers{3, 2, 1, 4, 5, 6, 6}; //新增的内容
	//list<int> numbers{3, 2, 1, 4, 5, 6};

	//sort要求的是随机访问迭代器,array  vector  deque
	sort(numbers.begin(), numbers.end());

    //问题思考：如何加快查找速度？有序以后，二分查找比较快


	//元素经过排序之后，再查找，能加快查找的速度  O(logN)
	if(binary_search(numbers.begin(), numbers.end(), 6)) {
		cout << "查找成功" << endl;
	} else {
		cout << "查找失败" << endl;
	}

	return 0;
}

int test1(void)
{
	vector<int> numbers{3, 2, 1, 4, 5, 6, 1, 2, 4, 3, 5, 6, 4, 7, 4};
	//list<int> numbers{3, 2, 1, 4, 5, 6};

	//sort要求的是随机访问迭代器
	sort(numbers.begin(), numbers.end());

	//元素经过排序之后，再查找，能加快查找的速度  O(logN)
	auto lit = std::lower_bound(numbers.begin(), numbers.end(), 4);
	auto uit = std::upper_bound(numbers.begin(), numbers.end(), 4);
	for(; lit != uit; ++lit)
	{
		cout << * lit << " ";
	}
	cout << endl;

	return 0;
}

int main(void)
{
    //test0();
	test1();
	return 0;
}
