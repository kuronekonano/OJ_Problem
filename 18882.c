#include<stdio.h>
int main()
{
    int i,n,sum;
    while(scanf("%d",&n)&&n!=0)
    {
        sum=0;
        int a[100];
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
