#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

int get_onlyone(int array[], int size)
{
    //int array[SIZE] = { 1, 2, 3, 4, 5, 6,1, 2, 3, 4, 5 };
    int one = 0;
    for (int idx = 0; idx != size; ++idx) {
        one ^= array[idx];
    }
    //printf("唯一的数为: %d\n", xor);
    return one;
}

int main()
{   
    int array[11] = { 1, 2, 3, 4, 5, 6,1, 2, 3, 4, 5 };
    cout<<get_onlyone(array,11)<<endl;    
    return 0;
}
