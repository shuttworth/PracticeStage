#include "Country.h"
#include <memory>
using std::unique_ptr;



void test0()
{
    UnitedNations * unionsec = new SecurityCouncil();
    unique_ptr<CertainCountry> coun1 (new CertainCountry("America"));
    unique_ptr<CertainCountry> coun2 (new CertainCountry("Iraq"));
    
    coun1->Declare(unionsec,"你动了我的石油霸权，洗衣服也要把你打下台");
    coun2->Declare(unionsec,"王侯将相，宁有种乎");
}



int main()
{
    test0();
    return 0;
}

