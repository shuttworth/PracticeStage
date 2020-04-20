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
using std::remove;
 
int main(void)
{
	vector<int> numbers{4, 3, 2, 4, 1, 4, 5, 6, 4};
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

    //仅仅remove操作,无法实现真正的删除操作，理解了remove的指针移动就知道了原因
    remove(numbers.begin(), numbers.end(), 4),numbers.end();


#if 1
	//erase-remove惯用法
	numbers.erase(remove(numbers.begin(), numbers.end(), 4),
				  numbers.end());
#endif	

	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
