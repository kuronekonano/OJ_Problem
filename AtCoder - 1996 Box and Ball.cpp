#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool vis[100005];
    int a[100005],n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++)a[i]=1;
        memset(vis,false,sizeof(vis));
        vis[1]=true;
        int x,y;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            a[x]--;
            a[y]++;
            if(vis[x])vis[y]=true;
            if(a[x]==0)vis[x]=false;
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(a[i]&&vis[i])ans++;
        printf("%d\n",ans);
    }
}
