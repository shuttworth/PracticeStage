#include "Observer.h"
#include "Notifier.h"
#include <memory>
using std::unique_ptr;

using namespace ob;

void test0()
{
    /* unique_ptr<Notifier> zed(new BossNotifier()); */
    Notifier * zed = new BossNotifier();

    Observer * ob1 = new StockObserver("张三",zed);
    Observer * ob2 = new StockObserver("罗翔",zed);
    Observer * ob3 = new LOLObserver("阿水",zed);
    Observer * ob4 = new LOLObserver("shy哥",zed);

    zed->attach(ob1);
    zed->attach(ob2);
    zed->attach(ob3);
    zed->attach(ob4);

    zed->setStatus("你要上演王者归来嘛？");

    zed->notifyAll();
    
    delete zed;
    delete ob1;
    delete ob2;
    delete ob3;
    delete ob4;
}



int main()
{
    test0();
    return 0;
}

