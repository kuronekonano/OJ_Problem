#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int r,c;
int a[105][105];//高度数组
int vis[105][105];//标记并记录长度的数组
int walkx[4]= {0,1,-1,0};///四个方向搜索迈进
int walky[4]= {1,0,0,-1};
int dfs(int x,int y)
{
    if(vis[x][y]!=0)//若被标记过，说明之前的搜索中找过这个坐标去往山底的路径，直接取这个坐标中存储的路径，即返回vis[x][y]
    {
        return vis[x][y];//记忆化搜索，此处仅用于加快搜索速度，不用于返回到主函数中
    }
    vis[x][y]=1;//计算的是长度，一个数字为一个长度，若遇到从未标记的坐标，设当前长度为1
    int nx,ny,i;
    for(i=0; i<4; i++)
    {
        nx=x+walkx[i];
        ny=y+walky[i];
        if(nx>0&&ny>0&&nx<=r&&ny<=c&&a[nx][ny]<a[x][y])
        {
            vis[x][y]=max(vis[x][y],dfs(nx,ny)+1);
        }
    }
    return vis[x][y];//走不下去时直接返回那个坐标，且坐标内存的是已走步数【唯一判断是否是最终点的返回值】
}

int main()
{
    int i,j;
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(i=1; i<=r; i++)///输入部分
        {
            for(j=1; j<=c; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(vis,0,sizeof(vis));///清空标记数组，同时也是计步数数组
        int sum=0;
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                sum=max(sum,dfs(i,j));//深搜每一个点到最终的步数，一直遍历完整个矩阵
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
