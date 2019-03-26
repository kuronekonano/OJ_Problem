#include<stdio.h>
int main()
{
    int n,m,k,i;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int sum=1,ans=1;
        if(n==1)
        {
            printf("%d\n",m);
            continue;
        }
        m-=n;
        if(m==0)
        {
            printf("1\n");
            continue;
        }
        while(m>0)
        {
            if(k+ans<=n)sum++;
            if(k-ans>=1)sum++;
            m-=sum;
            ans++;
        }
        printf("%d\n",ans);
    }
}
