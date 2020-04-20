#include "GameRole.h"
#include "MementoCarer.h"

void test0()
{
    GameRole alex(800,70,60);
    cout<<"浪完了，我要单挑盖侬"<<endl;
    alex.DisplayState();//初始化完毕，并且展示
    cout<<endl;

    cout<<"救公主之前存个档"<<endl;
    MementoCarer  _carer(alex.SaveTheState());
    //打boss之前存档
    cout<<endl;

    //被boss干掉
    alex.SetState(0,0,0);
    cout<<"被盖侬打败了(●—●)"<<endl;
    alex.DisplayState();
    cout<<endl;

    //读档
    alex.LoadBackState(_carer.getMemento());
    cout<<"读档再来，大师剑60攻冲冲冲"<<endl;
    alex.DisplayState();
    cout<<endl;

    cout<<"塞尔达，我重新来就你啦"<<endl;

}



int main()
{
    test0();
    return 0;
}

