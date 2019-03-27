#include<bits/stdc++.h>
using namespace std;
struct node///对于队列中每个节点，一个值表示坐标，也就是在模拟二维数组中一维数组的下标
{///以及一个表示到达当前位置的时间，因为根据到达某个位置的时间不同，异或值会不同
    int pos,time;
    node (int x,int y)///构造函数
    {
        pos=x;
        time=y;
    }
};
queue<node>q;///此处的标记用了3个状态，一个是一次都没走，用-1表示，一个是走了一次，记录走过的那一次是什么状态，第三种是走过两次，不再走这个节点
int t,n,m,a[100008],sx,sy,ex,ey,vis[100005];///因为n*m一定小于1e5，因此用一维数组模拟二维数组
bool dir(int pos,int time)///判断行走方向，根据到达该点时间判断异或值，是横走还是竖走
{
    if(time%2==0&&a[pos]==0||time%2==1&&a[pos]==1)return true;///竖走
    else return false;///横走
}
bool judge(int x,int y,int time)///判断该点是否能走
{
    if(x>=0&&x<n&&y>=0&&y<m)///若超出地图则不走
    {
        if(vis[x*m+y]==-1)///若一次没走过，必走，并且记录第一次走该点的状态
        {
            vis[x*m+y]=dir(x*m+y,time)?0:1;
            return true;
        }
        if(vis[x*m+y]==0&&dir(x*m+y,time)==1)return false;///如果走过一次，并且第二次遇到仍然是相同的状态则不走
        if(vis[x*m+y]==0&&dir(x*m+y,time)==0)///若是不同的状态，可以走，并且标记为走过两次
        {
            vis[x*m+y]=2;
            return true;
        }
        if(vis[x*m+y]==1&&dir(x*m+y,time)==1)
        {
            vis[x*m+y]=2;
            return true;
        }
        if(vis[x*m+y]==1&&dir(x*m+y,time)==0)return false;
        if(vis[x*m+y]==2)return false;///遇到了走过两次的点则不走
    }
    return false;

}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        while(!q.empty())q.pop();
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n*m; i++) vis[i]=-1;///初始化标记数组
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&a[i*m+j]);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        node st=node((sx-1)*m+sy-1,0);
        node ed=node((ex-1)*m+ey-1,0);
        vis[st.pos]=a[st.pos];///起点标记
        q.push(st);
        int ans=0x7fffffff;
        while(!q.empty())
        {
            node top=q.front();
            q.pop();
            int tmx=top.pos/m;///计算坐标
            int tmy=top.pos%m;
            int tim=top.time;
//            printf("==%d   %d   %d==\n",tmx,tmy,tim);
            if(tmx==ed.pos/m&&tmy==ed.pos%m)///判断是否到达终点
            {
                ans=tim>ans?ans:tim;
                break;
            }
            if(dir(tmx*m+tmy,tim))///竖走
            {
                tim++;
                if(judge(tmx+1,tmy,tim)) q.push(node((tmx+1)*m+tmy,tim));///向下
                if(judge(tmx-1,tmy,tim)) q.push(node((tmx-1)*m+tmy,tim));///向上
            }
            else///横走
            {
                tim++;
                if(judge(tmx,tmy-1,tim))q.push(node(tmx*m+tmy-1,tim));///向右
                if(judge(tmx,tmy+1,tim))q.push(node(tmx*m+tmy+1,tim));///向左
            }
        }
        printf("%d\n",ans==0x7fffffff?-1:ans);///判断是否走得通
    }
}
