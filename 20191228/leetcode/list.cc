#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
 
int main(void)
{
	list<int> li {1, 2, 3, 4, 5, 6};
	auto it = li.begin();
	std::advance(it, 3);
	cout << "*it = " << *it << endl;
	for(auto & number : li) 
		cout << number << " ";
	cout << endl;

	li.splice(li.begin(), li, it); //C++ 手册splice的第二种用法，第一个参数是插入内容到其前的元素，第二个元素是选定容器（可以自身可以别的），第三个参数是要转移的元素

	for(auto & number : li) 
		cout << number << " ";
	cout << endl;
 
	return 0;
}
