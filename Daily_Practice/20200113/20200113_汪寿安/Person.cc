#include <string.h>
#include <iostream>


using std::cout;
using std::endl;

#if 0
构建一个类Person，包含字符串成员name（姓名），整型数据成员age（年龄），成员函数
display（）用来输出name和age。构造函数包含两个参数，用来对name和age初始化。

构建一个类Employee由Person派生，包含department（部门），实型数据成员salary（工资）,
成员函数display（）用来输出职工姓名、年龄、部门、工资，其他成员根据需要自己设定。

主函数中定义3个Employee类对象，内容自己设定，将其姓名、年龄、部门、工资输出，
并计算他们的平均工资。
#endif

class Person
{
    public:
        Person(const char* name,int age )
        :_name(new char[strlen(name)+1]())
         ,_age(age)
    {
        strcpy(_name,name);
    }
        
    void display() const
    {
        cout<<"姓名是"<<_name<<endl;
        cout<<"年龄是"<<_age<<endl;
    }

    private:
        char * _name;
        int _age;
};

class Employee : public Person
{
public:
    Employee(const char * name,int age,const char * department,int salary)
    :Person(name,age)
     ,_department(new char[strlen(department)+1]())
     ,_salary(salary)
    {
        strcpy(_department,department);
    }

    void display() const
    {
        Person::display();
        cout<<"部门是"<<_department<<endl;
        cout<<"工资是"<<_salary<<endl;
    }

    int printSalary()const
    {
        return _salary;      
    }


private:
    char * _department;
    int _salary;

};


int main()
{
    Employee emp1("ming",21,"support",1000);
    Employee emp2("rookie",22,"mid",2000);
    Employee emp3("the shy",20,"head",1500);
    emp1.display();
    cout<<endl;
    emp2.display();
    cout<<endl;
    emp3.display();
    cout<<endl;
    double avg= (emp1.printSalary()+emp2.printSalary()+emp3.printSalary())/3;
    cout<<"平均工资为"<<avg<<endl;
    return 0;
}

