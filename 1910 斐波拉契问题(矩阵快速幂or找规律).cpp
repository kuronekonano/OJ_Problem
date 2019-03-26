#include<stdio.h>///找规律:首项是 2，公差为 4的n值都能被3整除An=2+4*(n-1)
int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%s\n",(n+2)%4==0?"Yes":"No");
    }
}
