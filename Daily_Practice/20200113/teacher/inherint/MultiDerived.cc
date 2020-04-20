///
/// @file    MultiDerived.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-13 16:21:42
///

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Fairy {
public:
	Fairy() {	cout << "Fairy()" << endl;}

	void fly() {	cout << " can fly.\n";}
};

class Monster {
public:
	Monster() {	cout << "Monster()" << endl;}
	void attack() {	cout << " take an attack.\n";	}
};

//class的默认继承权限是private
class Monkey 
: public Fairy
, public Monster {
public:
	Monkey(const string & name)
	: _name(name)
	{	cout << "Monkey()" << endl;	}

	void print() {
		cout << _name << " ";
	}
private:
	string _name;
};

void test() {
	Monkey sunWukong("Sun Wukong");
	sunWukong.print();
	sunWukong.fly();
	sunWukong.print();
	sunWukong.attack();
}

int main(void)
{
	test();

	return 0;
}
