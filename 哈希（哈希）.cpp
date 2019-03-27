#include<stdio.h>//²¢²»ÊÇ¹þÏ£
#include<string.h>
int a[1000010];
int main()
{
    int n,t,x,j;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&j);
            a[j]++;
        }
        for(int i=1;i<=t;i++)
        {
            scanf("%d",&x);
            printf("%d\n",a[x]);
        }
    }
    return 0;
}
