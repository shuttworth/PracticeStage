#pragma once
#include <iostream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;


class player
{
public:

    player(string name)
    :_name(name)
    {}

    virtual ~player() {}

    virtual void Attack() = 0;
    virtual void Defense() = 0;

protected:
    string _name;
};


class Forwards
:public player
{
public:
    Forwards(string name)
    :player(name)
    {}
    
    void Attack() override 
    {
        cout<<"Forwards "<<_name<<"is Attacking!"<<endl;
    }
    void Defense() override 
    {
        cout<<"Forwards "<<_name<<"is Defensing!"<<endl;
    }

};

class Center
:public player
{
public:
    Center(string name)
    :player(name)
    {}
    
    void Attack() override 
    {
        cout<<"Center "<<_name<<"is Attacking!"<<endl;
    }
    void Defense() override 
    {
        cout<<"Center "<<_name<<"is Defensing!"<<endl;
    }

};

class Guards
:public player
{
public:
    Guards(string name)
    :player(name)
    {}
    
    void Attack() override 
    {
        cout<<"Guards "<<_name<<"is Attacking!"<<endl;
    }
    void Defense() override 
    {
        cout<<"Guards "<<_name<<"is Defensing!"<<endl;
    }

};

class ForeignCenter
{
public:
    ForeignCenter(string name)
    :_name(name)
    {}

    void tomato()
    {
        cout<<"ForeignCenter "<<_name<<"is shouting tomato to Attack!"<<endl;
    }
    void jiong()
    {
        cout<<"ForeignCenter "<<_name<<"is showing his funny face 囧 to Defense!"<<endl;
    }
    
    void setName(string name)
    {
        _name = name;
    }
private:
    string _name;
    
};


class Translator
:public player
{
public:
    Translator(string name)
    :player(name)
    ,_for(new ForeignCenter(name)) 
    {
        /* _for->setName(name); */
    }

    void Attack() override 
    {
        _for->tomato();
    }
    void Defense() override 
    {
        _for->jiong();
    }
private:
    ForeignCenter * _for;
};






