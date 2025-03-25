#include<stdio.h>
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%X\n",a+b);//%x输出十六进制，%d输出十进制，%o输出八进制
    }
    return 0;
}
