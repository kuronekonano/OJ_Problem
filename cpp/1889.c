#include<stdio.h>
int main()
{
    int j,i,m,n;
    scanf("%d",&m);
    int a[m];
    for(i=1;i<=m;i++)
    {
        scanf("%d",&n);
        int b[n];
        int sum=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&b[j]);
            sum=sum+b[j];
        }
        a[i]=sum;
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
