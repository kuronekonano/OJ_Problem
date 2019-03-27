#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,t;
int tri[305][305][102];///三维数组，二维表示坐标，三维表示该数字出现次数，前缀和即区域数字出现次数
int a[305][305];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int num)
{
    for(int i=x; i<=n; i+=lowbit(i))///对二维区域进行遍历，更新每个数字出现的次数
        for(int j=y; j<=m; j+=lowbit(j))
            tri[i][j][num]++;
}
void del(int x,int y,int num)
{
    for(int i=x; i<=n; i+=lowbit(i))///若对数字进行更改则删除某数字的出现次数影响
        for(int j=y; j<=m; j+=lowbit(j))
            tri[i][j][num]--;
}
int sum(int x,int y,int z)///从目标坐标求和至1,1位置，得到整块区域的前缀和
{
    int sum=0;
    for(int i=x; i>0; i-=lowbit(i))
        for(int j=y; j>0; j-=lowbit(j))
            sum+=tri[i][j][z];
    return sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(tri,0,sizeof(tri));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&a[i][j]);
            update(i,j,a[i][j]);
        }
    scanf("%d",&t);
    while(t--)
    {
//        printf("=====%d\n",t);
        int flag;
        scanf("%d",&flag);
        if(flag==1)
        {
            int x,y,tmp;
            scanf("%d%d%d",&x,&y,&tmp);
            del(x,y,a[x][y]);
            a[x][y]=tmp;
            update(x,y,tmp);
        }
        else
        {
            int x1,x2,y1,y2,tmp,ans=0;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&tmp);
            ans=sum(x2,y2,tmp)-sum(x1-1,y2,tmp)-sum(x2,y1-1,tmp)+sum(x1-1,y1-1,tmp);///容斥原理，对于求和函数得到从1,1开始到右下角节点的全部区域前缀和，那么要减去两个多余的区域，加回被减去两次的区域
            printf("%d\n",ans);
        }
    }
}
