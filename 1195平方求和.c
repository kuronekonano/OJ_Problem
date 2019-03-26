#include<stdio.h>
#include<math.h>
int main()
{
    int sum,n,i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(i%2!=0)
            {
                sum=sum+pow(i,2);
            }
            continue;
        }
        printf("%d\n",sum);
    }
    return 0;
}
