#include<stdio.h>
int main()
{
    int a,b,c,d,e,n;
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)!=EOF)//Õ¨”‡∂®¿Ì
    {
        n=((a%e)*(b%e)*(c%e)*(d%e))%e;
        printf("%d\n",n);
    }
    return 0;
}
