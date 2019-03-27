#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
double dist[maxn],mp[maxn][maxn];
bool vis[maxn];
int n;
void SPFA(int s)
{
    queue<int>q;
    while(!q.empty())q.pop();
    for(int i=0; i<=n; i++)dist[i]=1e10;
    memset(vis,false,sizeof vis);
    dist[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        vis[top]=false;
        for(int i=1; i<=n; i++)
        {
            if(dist[i]>dist[top]+mp[top][i])
            {
                dist[i]=dist[top]+mp[top][i];
                if(!vis[i])
                {
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }
}
double cal(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double x[maxn],y[maxn],r[maxn];
int main()
{
    while(scanf("%lf%lf%lf%lf",&x[1],&y[1],&x[2],&y[2])!=EOF)
    {
        scanf("%d",&n);
        n+=2;
        r[1]=r[2]=0;
        mp[2][1]=mp[1][2]=cal(x[1],y[1],x[2],y[2]);
        for(int i=3; i<=n; i++)
        {
            scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
            for(int j=1; j<i; j++)
            {
                double tmp=cal(x[i],y[i],x[j],y[j]);
                if(r[i]+r[j]>tmp) mp[j][i]=0;
                else mp[i][j]=mp[j][i]=tmp-r[i]-r[j];
            }
        }
        SPFA(1);
        printf("%.9f\n",dist[2]);
    }
}
