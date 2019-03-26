#include<stdio.h>
int main()
{
    int m,a,b;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
            return 0;
        scanf("%d%d",&a,&b);
        a=a+b;///直接计算A+B
        int c[100000],flag=0;
        while(a)///进制转换循环
        {
            c[flag++]=a%m;///求模过程，存储位数是倒着存的
            a/=m;
        }
        for(int i=flag-1;i>=0;i--)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}
