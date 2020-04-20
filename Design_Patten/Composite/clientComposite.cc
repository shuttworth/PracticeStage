#include "Company.h"


void test0()
{
    ConcreteCompany root("北京总公司");
    root.addCom(new HRdepartment("北京总公司人力资源部"));
    root.addCom(new ProductDepartment("北京总公司产品部"));
    root.addCom(new MarketDepartment("北京总公司市场部"));

    ConcreteCompany * camp1 = new ConcreteCompany("华东分公司");
    camp1->addCom(new HRdepartment("华东分公司人力资源部"));
    camp1->addCom(new ProductDepartment("华东分公司产品部"));
    camp1->addCom(new MarketDepartment("华东分公司市场部"));
    root.addCom(camp1);

    cout<<"结构图:"<<endl;
    root.Display(1);

    cout<<"职责图:"<<endl;
    root.ShowDuty();
}








int main()
{
    test0();
    return 0;
}

