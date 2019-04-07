#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::pair;
 
template <typename Container>
void display(const Container & c) {
	typename Container::const_iterator cit = c.begin();
	while(cit != c.end())
	{
		cout << cit->first << " ---> " << cit->second << endl;
		++cit;
	}
}

void test0()
{
	//multimap能存放关键字相同的元素，默认情况下也是按升序进行排列
	multimap<int, string> cities{
		pair<int, string>(1, "北京"),
		pair<int, string>(2, "上海"),
		pair<int, string>(3, "广州"),
		pair<int, string>(4, "深圳"),
		pair<int, string>(5, "杭州"),
		pair<int, string>(2, "武汉"),
		pair<int, string>(3, "南京"),
	};
	//multimap不支持下标访问运算符；
	display(cities);
}
#if 1

void test1()
{
	//multimap不能存放关键字相同的元素，默认情况下也是按升序进行排列
	multimap<string, string> cities{
		pair<string, string>("11", "北京"),
		std::make_pair("22", "上海"),
		std::make_pair("33", "广州"),
		std::make_pair("44", "深圳"),
		std::make_pair("55", "杭州"),
		std::make_pair("22", "武汉"),
		std::make_pair("33", "南京"),
	};

	//multimap支持下标访问运算符；
	display(cities);
	//cout << cities["11"] << endl;//下标访问运算符第二个参数可以是任意类型

	//只查找
	cout << cities.count("22") << endl;
	cout << cities.count("77") << endl;
	display(cities);
	cout << endl;

	auto it = cities.find("77");
	if(it != cities.end())
		cout << it->first << " --> " << it->second << endl;
	else
		cout << "77 找不到" << endl;
	cout << endl;
	display(cities);
	cout << endl;

	//范围查找
	
	auto lit = cities.lower_bound("22");
	auto uit = cities.upper_bound("22");
	for(; lit != uit; ++lit) {
		cout << lit->first << " --> " << lit->second << endl;
	}

	cout << "*uit = " << uit->first << "---> " << uit->second << endl;
}
#endif

int main(void)
{
	test0();
//	test1();
	return 0;
}
