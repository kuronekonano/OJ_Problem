#include<stdio.h>
int main()
{
    int n,t;
    long long a[10005];
    a[1]=2;
    for(int i=2;i<=10000;i++)
    {
        a[i]=a[i-1]+6*(i-1);///用三个三角形最多可以把平面分成几个区域的递推公式
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
