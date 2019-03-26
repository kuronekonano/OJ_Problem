#include<stdio.h>
int main()
{
    long long int a,b;//32位有符号整形范围内 int: -21,0000,0000~21,0000,0000(十位）
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("%lld\n",a+b);
    }
    return 0;
}
