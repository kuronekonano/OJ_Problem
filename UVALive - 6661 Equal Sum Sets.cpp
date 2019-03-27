#include<stdio.h>///µÝ¹éË®Ìâ
#include<string.h>
bool vis[30];
int n,k,s,ans;
void dfs(int k,int sum,int st)
{
    if(k==0&&sum==s)
    {
        ans++;
        return;
    }
    if(k==0)return;
    for(int i=st; i<=n; i++)
    {
        if(sum+i>s)return;
        if(!vis[i])
        {
            vis[i]=true;
            dfs(k-1,sum+i,i);
            vis[i]=false;
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&s)!=EOF)
    {
        if(!n&&!k&&!s)return 0;
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(k,0,1);
        printf("%d\n",ans);
    }
}
