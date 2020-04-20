#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::ostream_iterator;
 
int main(void)
{
	vector<int> numbers{3, 2, 1, 4, 5, 6};
	list<int> li{11, 12, 13, 22, 33, 44};

	std::copy_if(li.begin(), li.end(), std::back_inserter(numbers), [](int number){ //第四个参数是条件
		if(number < 22)
			return true;
		else 
			return false;
	});

	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	

	return 0;
}
