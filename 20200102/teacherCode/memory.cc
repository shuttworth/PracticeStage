#include <iostream>
using std::cout;
using std::endl;

//全局静态区
int a = 0;
char * p1;
 
int main(void)
{
	int b;//栈区
	char s[] = "123456";
	char * p2;
	char * p3 = "123456";//C++11不允许指针指向文字常量区
	//*p3 = 'A';
	static int c = 0;//全局静态区
	p1 = new char[10];//堆
	p2 = new char[5];

	printf("&a = %p\n", &a);
	printf("p1 = %p\n", p1); 
	printf("&p1 = %p\n", &p1);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("p2 = %p\n", p2); 
	printf("&p2 = %p\n", &p2);

	printf("p3 = %p\n", p3); 
	printf("&p3 = %p\n", &p3);
	printf("s = %p\n", s);
	printf("main = %p\n", &main);//程序代码区
	printf("main = %p\n", main);
 

	return 0;
}
