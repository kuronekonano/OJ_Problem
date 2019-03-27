#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
struct edge
{
    double x,yu,yd;
    int flag;
    edge() {};
    edge(double a,double b,double c,int d)
    {
        x=a;
        yd=b;
        yu=c;
        flag=d;
    }
    bool operator <(const edge &a)
    {
        return x<a.x;
    }
} a[maxn];
int n;
struct node
{
    int l,r,cnt;
    double len,ren,dis;
} tre[maxn<<2];
double y[maxn];
void build(int l,int r,int rt)
{
    tre[rt].l=l;
    tre[rt].r=r;
    tre[rt].len=y[l];
    tre[rt].ren=y[r];
    tre[rt].cnt=0;
    if(tre[rt].l+1==tre[rt].r) return;
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid,r,rt<<1|1);
}
void cal_dis(int rt)
{
    if(tre[rt].cnt>0) tre[rt].dis=tre[rt].ren-tre[rt].len;///若覆盖计数大于0，该区间的覆盖面积为区间长度
    else if(tre[rt].r-tre[rt].l==1)  tre[rt].dis=0;///叶子节点
    else tre[rt].dis=tre[rt<<1].dis+tre[rt<<1|1].dis;///不是叶子节点，通过向上传递，两个子节点的dis之和即更大区间的dis
    return ;
}
void update(edge line,int rt)
{
    if(tre[rt].len==line.yd&&tre[rt].ren==line.yu)
    {
        tre[rt].cnt+=line.flag;
        cal_dis(rt);
        return ;
    }
    if(line.yu<=tre[rt<<1].ren) update(line,rt<<1);
    else if(line.yd>=tre[rt<<1|1].len) update(line,rt<<1|1);
    else
    {
        edge tmp=line;
        tmp.yu=tre[rt<<1].ren;
        update(tmp,rt<<1);
        tmp=line;
        tmp.yd=tre[rt<<1|1].len;
        update(tmp,rt<<1|1);
    }
    cal_dis(rt);
    return;
}
int main()
{
    double x1,y1,x2,y2;
    int cas=1;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int num=1;
        if(n==0)break;
        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            y[num]=y1;
            a[num++]=edge(x1,y1,y2,1);
            y[num]=y2;
            a[num++]=edge(x2,y1,y2,-1);
        }
        double ans=0;
        sort(a+1,a+num);
        sort(y+1,y+num);
        build(1,num-1,1);
        update(a[1],1);
        for(int i=2; i<num; i++)
        {
            ans+=tre[1].dis*(a[i].x-a[i-1].x);
            update(a[i],1);
        }
        printf("Test case #%d\n",cas++);
        printf("Total explored area: %.2f\n\n",ans);
    }
}
