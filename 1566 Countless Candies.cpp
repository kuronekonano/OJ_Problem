#include<stdio.h>///区间更新，可以用线段树来做·····orz
#include<string.h>
int main()
{
    int n,vis[100008];
    while(scanf("%d",&n)!=EOF)
    {
        int l,r;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&l,&r);
            vis[l]++;vis[r+1]--;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=vis[i];
            printf("%d%c",sum,i==n?'\n':' ');
        }
    }
}
