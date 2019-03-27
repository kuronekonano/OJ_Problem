#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct point
{
    int x,y,z;
}p[27008];
int l,r,c;
char a[32][32][32];
int vis[32][32][32];
int walkx[6]={0,0,0,0,1,-1};
int walky[6]={1,-1,0,0,0,0};
int walkz[6]={0,0,1,-1,0,0};
int main()
{
    int i,j;
    while(scanf("%d%d%d",&l,&r,&c)!=EOF)
    {
        if(!l&&!r&&!c)break;
        point in,out;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        queue<point>q;
        while(!q.empty())q.pop();
        for(i=0;i<l;i++)
        {
            for(j=0;j<r;j++)
            {
                scanf("%s",a[i][j]);
                for(int k=0;k<c;k++)
                {
                    if(a[i][j][k]=='S')
                    {
                        in.z=i;in.x=j;in.y=k;
                        q.push(in);
                    }
                    if(a[i][j][k]=='E')
                    {
                        out.z=i;out.x=j;out.y=k;
                    }
                }
            }
        }
        vis[in.z][in.x][in.y]=0;
        while(!q.empty())
        {
            point now=q.front();
            q.pop();
            for(i=0;i<6;i++)
            {
                int tmpx=now.x+walkx[i];
                int tmpy=now.y+walky[i];
                int tmpz=now.z+walkz[i];
                if(tmpx>=0&&tmpx<r&&tmpy>=0&&tmpy<c&&tmpz>=0&&tmpz<l&&a[tmpz][tmpx][tmpy]!='#'&&!vis[tmpz][tmpx][tmpy])
                {
                    point next;
                    next.x=tmpx;
                    next.y=tmpy;
                    next.z=tmpz;
                    vis[next.z][next.x][next.y]=vis[now.z][now.x][now.y]+1;
                    if(a[next.z][next.x][next.y]=='E')break;
                    q.push(next);
                }
            }
        }
        if(vis[out.z][out.x][out.y])
        {
            printf("Escaped in %d minute(s).\n",vis[out.z][out.x][out.y]);
        }
        else
        {
            printf("Trapped!\n");
        }
    }
}
