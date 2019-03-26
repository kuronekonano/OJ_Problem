#include<stdio.h>
int main()
{
    long long a,b,n=0x7fffffff,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a+b<-n-1||a+b>n)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
