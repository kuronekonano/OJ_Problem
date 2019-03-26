#include<stdio.h>
int main()///10的9次幂，不超过long long
{
    long long a,b;///输出的是a加上b倒过来的数
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        long long x=0;
        while(b!=0)
        {
            x=x*10+b%10;
            b=b/10;
        }
        printf("%lld\n",x+a);
    }
    return 0;
}
