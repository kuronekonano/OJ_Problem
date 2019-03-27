#include<stdio.h>///利用数组映射每个节点所到达的下一条line，并且利用link数组记录每个跳跃节点的高度
#include<string.h>
#include<algorithm>
using namespace std;
int ma[10004][10004],link[10004][10004];
int main()
{
    int t,n,m,l;
    scanf("%d",&t);
    while(t--)
    {
        int k,x;
        memset(link,0,sizeof(link));
        memset(ma,0,sizeof(ma));
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&k);
            ma[x][k]=x+1;///每条线的高度k位置映射到的line
            ma[x+1][k]=x;
            link[x][0]++;///数组中0位用于存储这条line的跳跃节点个数
            link[x+1][0]++;
            link[x][link[x][0]]=k;///添加新节点的高度
            link[x+1][link[x+1][0]]=k;
        }
        for(int i=0;i<n;i++)sort(link[i]+1,link[i]+1+link[i][0]);///记录每个k的位置，因为输入乱序，需要排序
        for(int i=0;i<n;i++)
        {
            int ans=i;k=0;
            while(1)
            {
                int tmp=*upper_bound(link[ans]+1,link[ans]+1+link[ans][0],k);///二分找出下一个连接点的高度
                if(tmp==0)break;///当找到的高度为0时，说明此时找到的位序已经比link[ans][0]大，找到了后面一个未赋值的元素，说明后面没有其他连接点，直接到达终点
                ans=ma[ans][tmp];///移动到该高度映射的line
                k=tmp;///得到当前高度，方便在下一个line中找新高度
            }
            printf("%d\n",ans);
        }
    }
}
