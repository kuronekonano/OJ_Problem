#include<stdio.h>
int main()///10��9���ݣ�������long long
{
    long long a,b;///�������a����b����������
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
