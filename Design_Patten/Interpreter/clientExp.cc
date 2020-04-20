#include "Expression.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Client，客户端
int main()
{
    PlayContext context;
    std::cout<<"上海滩："<<std::endl;

    context.SetText("O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3");

    Expression* expression;

    while(context.GetText().length()>0)
    {
        char c=context.GetText()[0];
        switch(c)
        {
        case 'O':
            expression=new Scale();
            break;
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'A':
        case 'B':
        case 'P':
            expression=new Note();
        }
    }
}
