#pragma once

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;


namespace paper{

class TestPaper
{
public:
    void question1()
    {
        cout<<"question1: what is your name"<<endl; 
        cout<<"anwser: "<<anwser1()<<endl;
    }

    void question2()
    {
        cout<<"question2: what is your age"<<endl; 
        cout<<"anwser: "<<anwser2()<<endl;
    }

    void question3()
    {
        cout<<"question3: what is your problem"<<endl; 
        cout<<"anwser: "<<anwser3()<<endl;
    }

    virtual string anwser1()
    {
        return "";
    }
    virtual string anwser2()
    {
        return "";
    }
    virtual string anwser3()
    {
        return "";
    }

    virtual ~TestPaper() {}
private:

};

class StudentPaperA
:public TestPaper
{
public:
    string anwser1() override
    {//name age problem
        return "geogee";
    }
    string anwser2() override
    {//name age problem
        return "22";
    }
    string anwser3() override
    {//name age problem
        return "I need a job";
    }
};

class StudentPaperB
:public TestPaper
{
public:
    string anwser1() override
    {//name age problem
        return "lisa";
    }
    string anwser2() override
    {//name age problem
        return "18";
    }
    string anwser3() override
    {//name age problem
        return "I am a little black";
    }
};





}//end of namespace paper
