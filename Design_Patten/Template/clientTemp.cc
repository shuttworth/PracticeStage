#include "TestPaper.h"
#include <memory>

using std::unique_ptr;
using namespace paper;

void test0()
{
    unique_ptr<TestPaper> host1 (new StudentPaperA());
    unique_ptr<TestPaper> host2 (new StudentPaperB());

    host1->question1();
    host1->question2();
    host1->question3();
    
    host2->question1();
    host2->question2();
    host2->question3();
}



int main()
{
    test0();
    return 0;
}
