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
using std::replace_if;
 
int main(void)
{
	vector<int> numbers{4, 3, 2, 4, 1, 4, 5, 6, 4};
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	std::less<int> lt;//lt(lhs, rhs)
	replace_if(numbers.begin(), 
			numbers.end(),
			//std::bind1st(lt, 4),  //1是与第一个绑定,2是与第二个绑定,C++11以后被弃用了，以后使用bind,可以绑定第三个、第四个参数等等
			std::bind2nd(lt, 4), // 函数适配器  
			10);

#if 0
	replace_if(numbers.begin(), numbers.end(), [](int number){
		if(number < 4)
			return true;
		else 
			return false;
	}, 10);
#endif
	
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
