#include<stdio.h>///三原色，就是取两两公倍数个数，然后因为有公共区间，被多减掉的部分加回来就好了
long long gcd(long long x,long long y)
{
    while(y!=0)///最大公约数
    {
        long long z=y;///这里要记住，常用这样的方法，临时存储b
        y=x%y;
        x=z;
    }
    return x;
}
long long lcm(long long a,long long b)///最小公倍数
{
    long long c=gcd(a,b);
    return a*b/c;
}
int main()
{
    long long x,y,z,n;
    while(scanf("%lld%lld%lld%lld",&x,&y,&z,&n)!=EOF)
    {
        long long red=lcm(x,y);///两色交叉部分，就是两数的最公倍数个数
        long long yellow=lcm(x,z);
        long long green=lcm(y,z);
        long long black=lcm(red,z);///三数交叉部分，被重复减掉的公倍数部分
        long long much=n/red+n/yellow+n/green-2*(n/black);///这里是统计所有作为三数公倍数的个数
        printf("%lld\n",n-much);///用总数减公倍数个数
    }
    return 0;///注意如果求n以内，有多少m的倍数，直接用n/m可求
}
