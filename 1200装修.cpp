#include<stdio.h>
int main()
{
    int c,n,a[35],i;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        a[1]=1;
        a[2]=3;
        a[3]=5;
        a[4]=11;
        for(i=5; i<=n; i++)
        {
            a[i]=a[i-1]+2*a[i-2];
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
