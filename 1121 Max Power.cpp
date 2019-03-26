#include<stdio.h>
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
        int max=0;
        if(n<4)
        {
            printf("%d\n",n);
        }
        else
        {
            for(int i=1; i<=n/2; i++)
            {
                a=i*(n-i);
                if(a>max)
                {
                    max=a;
                }
            }
            printf("%d\n",max);
        }
    }
    return 0;
}
