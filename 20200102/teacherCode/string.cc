 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-02 11:29:08
 ///
 
#include <string.h> //C头文件

#include <string> //C++头文件, 模板
#include <iostream>
using std::cout;
using std::endl;
using std::string;


void func(int arr[10])
//void func(int * arr)
{
	//一个指针的大小, 不会获取到数组的空间的大小的
	//cout << sizeof(arr) << endl;
}


//C语言中传递数组的写法
void func2(int * p, int size)
{
	//p[size -1]
}

void test0()
{
	char str1[] = "hello,world";//字符数组 栈区  以'\0'结尾
	//C风格字符串
	const char * pstr = "hello, wangdao";// 文字常量区(只读)
	printf("str1 = %p\n", str1);
	printf("pstr = %p\n", pstr);

	//str1 = 0x1000;//error  数组名是常量, 不能被修改

	//对于数组来说，sizeof求取的是数组本身所占空间的大小
	int len1 = sizeof(str1) - 1;
	//求取字符串的长度
	len1 = strlen(str1);
	cout << "len1 = " << len1 << endl;

	int len2 = sizeof(pstr);//求取的是指针的大小，32位 4字节，64位 8字节
	cout << "len2 = " << len2 << endl;
	len2 = strlen(pstr);
	cout << "len2 = " << len2 << endl;
	
	//做字符串的拼接操作
	char * pstr2 = (char*)malloc(len1 + len2 + 1);
	memset(pstr2, 0, len1 + len2 + 1);
	strcpy(pstr2, str1);
	strcat(pstr2, pstr);
	//strcat(str1, pstr);// 直接做操作，数组访问越界
	//printf("str1 = %s\n", str1);
	printf("pstr2= %s\n", pstr2);

	printf("pstr2[0] = %c\n", pstr2[0]);

	printf("address of %s is %p\n", "hello, wangdao", &"hello, wangdao");

	char * pstr3 = strstr(pstr2, "world");
	printf("pstr3 = %s\n", pstr3);

	free(pstr2);
}

void test1()
{
	//C++风格的字符串
	//
	//将C风格字符串转换为C++风格字符串
	string s1 = "hello,world"; //const char*
	string s2 = "hello,wangdao";

	cout << "s1.size() : " << s1.size() << endl;
	cout << "s1.length():" << s1.length() << endl;

	string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;

	//将C++风格字符串转换为C风格字符串
	const char * pstr = s3.c_str();
	printf("pstr = %s\n", pstr);

	string * pp = &s3;//ok
	//strstr(&s3, "world");//error
	
	//下标访问运算符

	/* for(size_t idx = 0; idx != s3.size(); ++idx) { */
	/* 	cout << s3[idx] << endl; */
	/* } */

	//遍历元素，从第一个到最后一个
	/* for(auto & ch : s3) { */
	/* 	cout << ch << endl; */
	/* } */

	//查找字符串
	size_t pos = s3.find("world");
	cout << "pos = " << pos << endl;

	//截取子串
	string s4 = s3.substr(pos, 5);
	cout << "s4 = " << s4 << endl;

	//拼接字符串
	string s5 = s4 + ",hello";
	cout << "s5 = " << s5 << endl;
	string s6 = s5 + 'A';
	cout << "s6 = " << s6 << endl;

	s1 += s2;
	cout << "s1 = " << s1 << endl;

	string s7 = s4.append(",hello");
	cout << "s7 = " << s7 << endl;
	string s8 = s7.append(3, 'A');
	cout << "s8 = " << s8 << endl;
	string s9 = s7.append(s1, 0, 5);
	cout << "s9 = " << s9 << endl;


	//字符串比较
	cout << "(s1 == s2)" << (s1 == s2)  << endl;
	cout << "(s1 != s2)" << (s1 != s2)  << endl;

}

void test2()
{
	int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	func(arr1);
}
// 
int main(void)
{
	
	/* test0(); */
	test1();
	//test2();
 
	return 0;
}
