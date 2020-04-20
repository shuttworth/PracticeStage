#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
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
	//map不能存放关键字相同的元素，默认情况下也是按升序进行排列
	map<int, string> cities{
		pair<int, string>(1, "北京"),
		pair<int, string>(2, "上海"),
		pair<int, string>(3, "广州"),
		pair<int, string>(4, "深圳"),
		pair<int, string>(5, "杭州"),
		pair<int, string>(2, "武汉"),
		pair<int, string>(3, "南京"),
	};
	display(cities);
	cout << cities[1] << endl;
	//map支持下标访问运算符；
	//
	//如果关键字key存在，则直接对应的value;
	//如果关键字key不存在，则直接创建一个
	cout << cities[6] << endl;
	cout << endl;
	display(cities);
	cities[6] = "武汉";
	cout << endl << "修改完value之后:" << endl;
	display(cities);
}

void test1()
{
	//map不能存放关键字相同的元素，默认情况下也是按升序进行排列
	map<string, string> cities{
		pair<string, string>("11", "北京"),
		std::make_pair("22", "上海"),
		std::make_pair("33", "广州"),
		std::make_pair("44", "深圳"),
		std::make_pair("55", "杭州"),
		std::make_pair("22", "武汉"),
		std::make_pair("33", "南京"),
	};

	display(cities);
	cout << cities["11"] << endl;//下标访问运算符第二个参数可以是任意类型
	//map支持下标访问运算符；
	//
	//如果关键字key存在，则直接对应的value;
	//如果关键字key不存在，则直接创建一个
	cout << cities["66"] << endl;
	cout << endl;
	display(cities);
	cities["66"] = "武汉";//下标访问运算符还可以修改数据, 时间复杂度O(logN)
	cout << endl << "修改完value之后:" << endl;
	display(cities);

	//只查找
	cout << cities.count("11") << endl;
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

	//添加元素
	
	//std::pair<map<string,string>::iterator, bool> ret = cities.insert(std::make_pair("66", "西安"));
	auto ret = cities.insert(std::make_pair("66", "西安"));
	if(ret.second) {
		cout << "添加元素成功" << endl;
		cout << ret.first->first << " --> " << ret.first->second << endl;
	} else {
		cout << "insert失败" << endl;
		cout << ret.first->first << " --> " << ret.first->second << endl;
	}
	display(cities);
}
int main(void)
{
	//test0();
	test1();
	return 0;
}
