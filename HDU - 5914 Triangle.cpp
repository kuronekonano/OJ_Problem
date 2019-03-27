#include<stdio.h>
#include<string.h>
int main()
{
    int n,t,i,a[25],cas=0;
    bool b[10000];
    memset(b,false,sizeof(b));
    b[1]=a[1]=1;
    a[2]=1;
    for(i=3;i<=20;i++)
    {
        a[i]=a[i-1]+a[i-2];
        b[a[i]]=true;
    }
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        int ans=0;
        for(i=1;i<=n;i++) if(!b[i])ans++;
        printf("Case #%d: %d\n",cas,ans);
    }
}
