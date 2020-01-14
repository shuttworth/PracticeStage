 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int * pint = (int *)malloc(sizeof(int));
	cout << "*pint = " << *pint << endl;

	return 0;
}
