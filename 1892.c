#include<stdio.h>
int main()
{
    long long int a,b;//32λ�з������η�Χ�� int: -21,0000,0000~21,0000,0000(ʮλ��
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("%lld\n",a+b);
    }
    return 0;
}
