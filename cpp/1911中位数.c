#include<stdio.h>
int main()
{
    int a,b,c,t;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a<b)
        {
            t=a;a=b;b=t;
        }
        if(a<c)
        {
            t=a;a=c;c=t;
        }
        if(b<c)
        {
            t=b;b=c;c=t;
        }
        printf("%d\n",b);
    }
    return 0;
}
