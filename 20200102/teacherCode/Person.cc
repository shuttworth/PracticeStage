 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


class Person {
public:
	//成员函数  （功能，接口，服务）
	void setName(const string & name)
	{	_name = name;	}

	void setId(int id)
	{	_id = id;	}

	void setMoney(int money)
	{	_money = money;	}

	int showMoney() {	return _money;	}

	void payMoney(int money, Person & p)
	{	
		_money -= money;
		p.setMoney(money + p.showMoney());
	}

	void getMoney(int money, Person & p)
	{	_money += money;	
		p.setMoney(p.showMoney() - money);
	}

private://数据成员, 封装
	string _name;
	int _id;
	int _money;
};
 
int main(void)
{
	Person ming;
	ming.setName("Ming");
	ming.setId(1);
	ming.setMoney(100);
 
	Person dong;
	dong.setName("Dong");
	dong.setId(2);
	dong.setMoney(100);

	Person yang;
	yang.setName("Yang");
	yang.setId(3);
	yang.setMoney(100);

	Person boss;
	boss.setName("Boss");
	boss.setId(4);
	boss.setMoney(0);

	Person er;
	er.setName("Xiaoer");
	er.setId(5);
	er.setMoney(0);

	ming.payMoney(100, boss);
	dong.payMoney(100, boss);
	yang.payMoney(100, boss);
	
	boss.payMoney(50, er);

	er.payMoney(10, ming);
	er.payMoney(10, dong);
	er.payMoney(10, yang);

	//cout << er._id << endl;
	//cout << er._money << endl;

	return 0;
}
