#include<stdio.h>///如4对中，3个人错排，那么，这三个人使用错排递推，得到种数，然后1个人是正确的选择
int main()///那一个人可能是四个中的一个，所以正确的排法有4种，于是每次正确的人排发不一样，错误的排列也不一样
{
    int n,m,i,t;///可以得到，有4倍的 错排种数
    long long a[25];
    a[1]=0;
    a[2]=1;
    for(i=3;i<=20;i++)
    {
        a[i]=(i-1)*(a[i-1]+a[i-2]);///错排递推公式
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        long long sum=1;
        for(i=n-m+1;i<=n;i++)///排列---组合数，Cij，四个中选3个
        {
            sum*=i;
        }
        for(i=1;i<=m;i++)
        {
            sum/=i;
        }
        printf("%lld\n",sum*a[m]);
    }
    return 0;
}
