#include <iostream>
using namespace std;

using std::cout;
using std::endl;


void swap  (int x, int y) 
{ int temp = x;  x = y;  y = temp;  }

int main(void) 
{ int a = 3, b = 4;
 cout << "a，b交换之前:" << endl; cout << "a = " << a << endl; 
cout << "b = " << b << endl << endl; 
swap(a, b); 
//swap(&a, &b);
cout << "a，b交换之后:" << endl; 
cout << "a = " << a << endl; 
cout << "b = " << b << endl;
return 0;
}
