#include<stdio.h>
int main()
{
    int i=0,n,n1,n2,n3,n4;
    while(scanf("%d",&n)!=EOF)
    {
        i++;
        if(n==0) return 0;
        n1=3*n;
        n2=n1%2==0?n1/2:(n1+1)/2;
        n3=3*n2;n4=n3/9;
        printf("%d%s %d\n",i,n%2==0?". even":". odd",n4);
    }
    return 0;
}
