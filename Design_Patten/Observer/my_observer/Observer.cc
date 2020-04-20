#include "Observer.h"

namespace ob{


void StockObserver::update()
{
    cout<<_noti->getStatus()<<_name<<" 关闭股票，继续工作 "<<endl;
}//通过打印操作模拟了关闭的操作
//观察者类的内部，定义了通知者这一数据成员，然后通过通知者getStatus来更新自己的状态


void LOLObserver::update()
{
    cout<<_noti->getStatus()<<_name<<" 关闭LOL，继续工作 "<<endl;
}





}//end of namespace ob
