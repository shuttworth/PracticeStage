#pragma once

#include <iostream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;


namespace res{

class workExperience{
public:
    /* workExperience(string workdate,string company) */
    /* :_workdate(workdate) */
    /* ,_company(company) */ 
    /* {} */
    void setWorkDate(string workdate)
    {
        _workdate = workdate;
    }

    void setCompany(string company)
    {
        _company = company;
    }

    string getWorkDate()
    {
        return _workdate; 
    }

    string getCompany()
    {
        return _company; 
    }
private:
    string _workdate;
    string _company;

};

class iCloneAble
{
public:
    virtual iCloneAble * clone() = 0;
    virtual ~iCloneAble() {}
};


class Resume
:public iCloneAble
{
public:
    Resume(string name)
    :_work(workExperience())
     ,_name(name)
    {}

    void setPersonInfo(string sex,string age)
    {
        _sex = sex;
        _age = age;
    }

    void setWorkExperience(string workdate,string company)
    {
        _work.setWorkDate(workdate);
        _work.setCompany(company);
    }

    void display()
    {
        cout<<_name<<"  "<<_sex<<"  "<<_age<<endl;
        cout<<"工作经历 "<<_work.getWorkDate()<<"  "<<_work.getCompany()<<endl;
    }

    //代码的核心
    Resume(const Resume & rhs)
    {
        //显示定义复制构造函数
        _work= rhs._work;
        _name= rhs._name;
        _sex= rhs._sex;
        _age= rhs._age;
    }

    Resume * clone() override
    {
       //调用复制构造函数 
       return new Resume(*this);
    }


private:
    workExperience _work;
    string _name;
    string _sex;
    string _age;
    
};



}//end of namespace res
