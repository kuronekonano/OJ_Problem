#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        printf("%d\n",a+b-c);
    }
    return 0;
}
