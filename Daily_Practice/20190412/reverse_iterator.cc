#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};
	vector<int>::reverse_iterator rit = numbers.rbegin();
	while(rit != numbers.rend()) {
		cout << *rit << " ";
		++rit;
	}

	cout << endl;

	return 0;
}
