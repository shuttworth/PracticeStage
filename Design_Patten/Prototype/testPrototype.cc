#include "Resume.h"

using namespace res;


void test0()
{
    Resume lilei("李磊");
    lilei.setPersonInfo("男","23");
    lilei.setWorkExperience("2016-2019","Mi");

    Resume  mark = *lilei.clone();
    mark.setPersonInfo("女","25");//后续可以加一个改名字的成员函数

    lilei.display();
    mark.display();

}





int main()
{
    test0();
    return 0;
}
