#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "sizeof(numbers) = " << sizeof(numbers) << endl;

	return 0;
}
