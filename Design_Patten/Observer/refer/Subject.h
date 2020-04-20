#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>

class Observer;

//Subject，抽象通知者或者主题
class Subject
{
protected:
    std::string SubjectState;
public:
    virtual void Attach(Observer* observer)=0; //增加
    virtual void Detach(Observer* observer)=0; //减少
    virtual void Notify()=0;                   //通知
    std::string GetSubjectState();             //获得通知者状态 
    void SetSubjectState(std::string state);   //设置通知者状态
    virtual ~Subject() {}                      //基类的析构函数设置成虚析构，必不可少 
};

//ConcreteSubject，具体通知者或者具体主题。
class Boss:public Subject
{
private:
    std::list<Observer*> observers;   //存放的是接受的请求list，通知时会挨个通知
    std::string action;
public:
    void Attach(Observer* observer);
    void Detach(Observer* observer);
    void Notify();
};

#endif
