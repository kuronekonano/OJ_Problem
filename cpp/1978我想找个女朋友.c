#include<stdio.h>
int main()
{
    int a,i,n;
    while(scanf("%d",&n)!=EOF)
    {
        a=0;
        for(i=1;i<=n;i++)
        {
            if(i%10==1)
            {
                a++;
            }
            if(i%100/10==1)
            {
                a++;
            }
            if(i%1000/100==1)
            {
                a++;
            }
            if(i%10000/1000==1)
            {
                a++;
            }
            if(i%100000/10000==1)
            {
                a++;
            }
            if(i%1000000/100000==1)
            {
                a++;
            }
        }
        printf("%d\n",a);
    }
    return 0;
}
