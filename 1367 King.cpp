#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int walkx[8]={1,-1,0,0,1,-1,-1,1};
int walky[8]={0,0,1,-1,-1,1,-1,1};
struct local
{
    int x,y;
};
int main()
{
    int i,j,t;
    int vis[10][10];
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        queue<local>q;
        char st[3],en[3];
        scanf("%s %s",st,en);
        if(strcmp(st,en)==0)
        {
            printf("0\n");
            continue;
        }
        local ks;
        ks.x=st[0]-'a'+1;
        ks.y=st[1]-'0';
        local js;
        js.x=en[0]-'a'+1;
        js.y=en[1]-'0';
        q.push(ks);
        vis[ks.x][ks.y]=0;
        while(!q.empty())
        {
            local tmp=q.front();
            q.pop();
            for(i=0;i<8;i++)
            {
                if(tmp.x+walkx[i]<=8&&tmp.x+walkx[i]>=1&&tmp.y+walky[i]<=8&&tmp.y+walky[i]>=1&&!vis[tmp.x+walkx[i]][tmp.y+walky[i]])
                {
                    local news;
                    news.x=tmp.x+walkx[i];
                    news.y=tmp.y+walky[i];
                    vis[news.x][news.y]=vis[tmp.x][tmp.y]+1;
                    q.push(news);
                }
            }
            if(vis[js.x][js.y])
            {
                break;
            }
        }
        printf("%d\n",vis[js.x][js.y]);
    }
    return 0;
}
