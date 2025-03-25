#include<stdio.h>
int main()
{
    int i,n;
    while(~scanf("%d",&n)&&n!=0)
    {
        int a[n];
        int sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
