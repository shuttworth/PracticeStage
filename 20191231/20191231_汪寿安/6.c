#include <stdio.h>
#include <stdlib.h>

void print_Column(char*str)
{
    //定义字母，数字，其他字符个数
    int alpN = 0, numN = 0, othN = 0;
    //hMax为三者中最大的数，h1,2,3分别为距离hMax的值
    int hMax = 0, h1 = 0, h2 = 0, h3 = 0;
    //指示标志，0表示没有打印最上面的数字，1表示已经打印了数字
    int flag1 = 0, flag2 = 0, flag3 = 0;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
        {
            alpN++;
        }
        else if ('0' <= str[i] && str[i] <= '9')
        {
            numN++;
        }
        else
        {
            othN++;
        }
    }
    printf("alpN=%d,numN=%d,othN=%d", alpN, numN, othN);

    //计算hMax
    hMax = othN > (alpN > numN ? alpN : numN) ? othN : (alpN > numN ? alpN : numN);
    //计算距离差值
    h1 = abs(alpN - hMax);
   h2 = abs(numN - hMax);
    h3 = abs(othN - hMax);
    printf("\nprint column.....\n");

    //开始打印
    //打印最上面的数字
    if (h1 == 0)
    {
        printf("  %d  ", alpN);
        flag1 = 1;
    }
    else
    {
        printf("      ");
    }
    printf("\t");
    if (h2 == 0)
    {
        printf("  %d  ", numN);
        flag2 = 1;
    }
    else
    {
        printf("      ");
    }
    printf("\t");
    if (h3 == 0)
    {
        printf("  %d  ", othN);
        flag3 = 1;
    }
    else
    {
        printf("      ");
    }
    printf("\n");

    //开始循环，总共有 hMax 遍
    for (i = 1; i <= hMax; i++)
    {
        //针对alp的打印
        if (flag1)
        {
            printf("*****");
        }
        else
        {
            h1--;
            if (h1 == 0)  //表示要打印数字了
            {
                printf("  %d  ", alpN);
                flag1 = 1;
            }
            else
            {
                printf("     ");
            }
        }
        printf("\t");

        //针对num的打印
        if (flag2)
        {
            printf("*****");
        }
        else
        {
            h2--;
            if (h2 == 0)  //表示要打印数字了
            {
                printf("  %d  ", numN);
                flag2 = 1;
            }
            else
            {
                printf("     ");
            }
        }
        printf("\t");

        //针对oth的打印
        if (flag3)
        {
            printf("*****");
        }
        else
        {
            h3--;
            if (h3 == 0)  //表示要打印数字了
            {
                printf("  %d  ", othN);
                flag3 = 1;
            }
            else
            {
                printf("     ");
            }
        }
        //打印完一行就换行
        printf("\n");
    }
    printf("  alp  \t");
    printf("  num  \t");
    printf("  oth  \t");
    printf("\n");

}
int main(){

    char str[81];
    printf("input a string:");
    gets(str);
    print_Column(str);
}

