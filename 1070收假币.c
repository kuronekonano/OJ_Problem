#include<stdio.h>
int main()
{
    int p1,p2,m,n;
    while(scanf("%d%d%d",&p1,&p2,&m)!=EOF)
    {
        n=p1+(m-p2);
        printf("%d\n",n);
    }
    return 0;
}
