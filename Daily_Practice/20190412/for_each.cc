#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::for_each;
using std::vector;

void display(int & number) 
{
	++number;
	cout << number << " ";
}
 
int main(void)
{
	vector<int> numbers{3, 2, 1, 4, 5, 6};

	for_each(numbers.begin(), numbers.end(), display);

	//匿名函数对象
	for_each(numbers.begin(), numbers.end(), [&](int number){
	
		cout << *numbers.begin() << " " << number << "\n";		
	});
	return 0;
}
