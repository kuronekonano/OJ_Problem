#include<stdio.h>
int main()
{
    int a,b,r1,r2;
    while(scanf("%d%d%d%d",&a,&b,&r1,&r2)!=EOF)
    {
        if((2*r1>a||2*r1>b)||(2*r2>a||2*r2>b)||((2*r1+2*r2)>a)||((2*r1+2*r2)>b))
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
