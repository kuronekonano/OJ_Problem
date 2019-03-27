#include<stdio.h>///LCA最近公共祖先朴素算法
#include<string.h>
#include<algorithm>
using namespace std;
int fa[100005];
int val[100005];
int deep(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x=fa[x];
    }
    return cnt;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y,w;
        memset(fa,0,sizeof(fa));
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&w);///关于建图，因为题目没有给出父子关系，也没有先后顺序
            if(fa[x]!=0)fa[y]=x,val[y]=w;///因此判断双方是否有父亲即可，如果都没有父亲默认x作父亲
            else fa[x]=y,val[x]=w;
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            int dx=deep(x),dy=deep(y);
            int minx=0x7fffffff,miny=0x7fffffff;///只需在回溯时不断维护当前最小权
            if(dx<dy)
            {
                int tt=dy-dx;
                while(tt--)
                {
                    miny=min(miny,val[y]);///注意先取最小权再向上回溯
                    y=fa[y];
                }
            }
            else if(dx>dy)
            {
                int tt=dx-dy;
                while(tt--)
                {
                    minx=min(minx,val[x]);
                    x=fa[x];
                }
            }
            while(x!=y)///每次回溯都先取最小权
            {
                minx=min(minx,val[x]);
                x=fa[x];
                miny=min(miny,val[y]);
                y=fa[y];
            }
            printf("%d\n",min(minx,miny));
        }
    }
}
