#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <deque>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::ostream_iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
using std::copy;
using std::deque;
 
int main(void)
{
	vector<int> vec{3, 2, 1, 4, 5, 6};
	list<int> li{11, 22, 33};
	deque<int> dque;
	set<int> setInt{8, 7, 9, 0};

	//back_insert_iterator调用push_back添加元素, 适用的容器有 vector,deque,list
	copy(li.begin(), li.end(), back_insert_iterator<vector<int>>(vec));
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//front_insert_iterator内部要调用push_front添加元素, 适用的容器 deque,list, forward_list
	copy(li.begin(), li.end(), front_insert_iterator<deque<int>>(dque));
	copy(dque.begin(), dque.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//insert_iterator内部要调用insert方法添加元素, 适用的容器deque,list,vector, set,map, unordered_set,unordered_map
	copy(li.begin(), li.end(), insert_iterator<set<int>>(setInt, ++setInt.begin()));
	copy(setInt.begin(), setInt.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
