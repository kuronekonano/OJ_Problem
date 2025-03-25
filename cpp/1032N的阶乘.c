#include<stdio.h>
int main()
{
    int n,i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=1;
        for(i=n;i>0;i--)
        {
            sum=sum*i;
        }
        printf("%d\n",sum);
    }
    return 0;
}
