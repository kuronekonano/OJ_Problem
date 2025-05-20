//#include<stdio.h>
//int main()
//{
//    int a,b,c;
//    while(scanf("%d%d",&a,&b)!=EOF)//对了！两数最小公倍数等于两数之积除以最大公约数
//    {
//        while(a%b!=0)
//        {
//            c=a%b;//辗转相除法（欧几里得算法）求最大公约数：如12，9：12%9=3，9%3=0，则最大公约数为3！
//            a=b;//递归思想
//            b=c;//若a<b时则将a,b位置调换
//        }
//        printf("%d\n",b);
//    }
//    return 0;
//}
#include<stdio.h>///递推法，注意是临时存储b值，放入a中，同样不会因为求模得0而出现无法进入循环的情况
long long gcd(long long a,long long b)
{
    while(b!=0)
    {
        long long c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
//        long long h=b;
//        long long t=a;
//        long long x;
//        x=t*h/gcd(a,b);
        printf("%lld\n",gcd(a,b));
//        printf("%lld\n",x);
    }
    return 0;
}
//#include<stdio.h>///1076递归法，这样不会出现无法进入GCD循环的情况
//unsigned long gcd(unsigned long a,unsigned long b)
//{
//    if(b==0) return a;
//    else return gcd(b, a%b);
//}
//int main()
//{
//    unsigned long a,b,c;
//    while(scanf("%lu%lu",&a,&b)!=EOF)
//    {
//        printf("%lu\n",gcd(a,b));
//    }
//    return 0;
//}
