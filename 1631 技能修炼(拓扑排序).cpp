#include<stdio.h>///Õÿ∆À≈≈–Ú
#include<string.h>
#include<queue>
using namespace std;
bool ma[502][502];
int vis[502];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int from,to;
        priority_queue<int,vector<int>,greater<int> >q;
        while(!q.empty())q.pop();
        memset(vis,0,sizeof(vis));
        memset(ma,false,sizeof(ma));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&from,&to);
            ma[from][to]=true;
            vis[to]++;
        }
        int num=0;
        for(int i=1;i<=n;i++)if(!vis[i])q.push(i),vis[i]=-1;
        while(!q.empty())
        {
            num++;
            int tmp=q.top();
            q.pop();
            printf("%d%c",tmp,num==n?'\n':' ');
            for(int i=1;i<=n;i++)
            {
                if(ma[tmp][i]&&vis[i])vis[i]--;
                if(vis[i]==0)q.push(i),vis[i]=-1;
            }
        }
    }
}
