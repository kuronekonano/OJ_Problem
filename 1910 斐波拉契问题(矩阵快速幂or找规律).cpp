#include<stdio.h>///�ҹ���:������ 2������Ϊ 4��nֵ���ܱ�3����An=2+4*(n-1)
int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%s\n",(n+2)%4==0?"Yes":"No");
    }
}
