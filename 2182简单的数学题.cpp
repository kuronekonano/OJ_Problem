#include<stdio.h>
#define N 1000000
int a[N+2];
int main()
{
    int i,j;
    for(i=1;i<=N;i++)///从1找到N，不是找因数，而是找倍数更快
    {
        for(j=i;j<=N;j+=i)///比如1，那就是每个以1为因数的（1的倍数）的数计数+1
        {///同理，每次是j=j+i，意思是找这个数的所有倍数，给他们的因数计数都加1
            a[j]++;///注意j要从i开始数，因为最小的j的倍数就是他本身
        }
    }
    for(i=1;i<=N;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
