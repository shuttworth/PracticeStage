#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::swap;

//swap在.cc文件里，需要声明std::swap
//swap在.c文件里，写 #include <algorithm> 即可


void findNum(int *a,int n)
{
    int ans=0;
    int pos=0;
    int x=0,y=0;
    for(int i=0;i<n;i++)
        ans^=a[i];
    int tmp=ans;
    while((tmp&1)==0){
    //终止条件是二进制tmp最低位是1
            pos++;
            tmp>>=1;
    }
    for(int i=0;i<n;i++){
        if((a[i]>>pos)&1){//取出第pos位的值
            x^=a[i];
        }
    }
    y=x^ans;
    if(x>y) swap(x,y);//从大到小输出x,y
    printf("%d %d\n",x,y);
}


//有102个整数，其中有50个数出现了两次，2个数出现了一次， 找出出现了一次的那2个数

//102个数里面找2个只出现一次的数,
//第一步：所有的数异或，得5^6的值，取pos=5^6&-5^6,可以把数分两堆
#define N 10
int main() {
	int a[N] = { 12,2,3,4,1,0,4,3,2,1 };
	int i;
	int result = 0;
	int result1 = 0;
	int result2 = 0;
	for (i = 0; i < N; i++) {
		result^= a[i];
	}
	int pos = result &(-1*result);//自己与自己的负数与，得到一个最低位为1的数,用来区分两个数很合适
	for (i = 0; i < N; i++) {
		if (pos&a[i]) {
			result1 ^=a[i];
		}
		else {
			result2 ^= a[i];
		}
	}
	printf("result1=%d,result2=%d\n ", result1,result2);
	return 0;
}




