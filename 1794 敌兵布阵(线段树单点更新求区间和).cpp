#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+9;
int t,n,ans,a[maxn];
struct node
{
    int l,r,sum;
}tre[maxn<<2];
void build(int l,int r,int rt)
{
    tre[rt].l=l;
    tre[rt].r=r;
    if(l==r)tre[rt].sum=a[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
    }
}
void update(int pos,int val,int rt)
{
    tre[rt].sum=tre[rt].sum+val;
    if(tre[rt].l==pos&&pos==tre[rt].r)return;
    int mid=(tre[rt].l+tre[rt].r)>>1;
    if(pos>mid) update(pos,val,rt<<1|1);
    else if(pos<=mid) update(pos,val,rt<<1);
}
void query(int l,int r,int rt)
{
    if(tre[rt].l>=l&&tre[rt].r<=r)ans+=tre[rt].sum;
    else
    {
        int mid=(tre[rt].l+tre[rt].r)>>1;
        if(mid<l)query(l,r,rt<<1|1);
        else if(mid>=r)query(l,r,rt<<1);
        else
        {
            query(l,r,rt<<1);
            query(l,r,rt<<1|1);
        }
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,n,1);
        char tmp[10];
        int l,r,val;
        printf("Case %d:\n",cas++);
        while(scanf("%s",tmp)!=EOF)
        {
            if(tmp[0]=='E') break;
            if(tmp[0]=='A')
            {
                scanf("%d%d",&l,&val);
                update(l,val,1);
            }
            if(tmp[0]=='S')
            {
                scanf("%d%d",&l,&val);
                update(l,-val,1);
            }
            if(tmp[0]=='Q')
            {
                scanf("%d%d",&l,&r);
                ans=0;
                query(l,r,1);
                printf("%d\n",ans);
            }

        }
    }
}


/**
#include<stdio.h>
#include<string.h>
#define N 50000
struct tree
{
    int l,r,sum;
} a[N*4];///一般定为最大值的四倍
int b[50003],sums;///b存储一初始每个营地的人数，sums存储最终区间内人数和
void build(int l,int r,int root)///建树
{
    a[root].l=l;///从第一个节点开始，左边是1，右边区间是n
    a[root].r=r;///之后递归时会改变root(节点)的值，因此每一个左范围和右范围都被定为传入函数中的l值和r值
    if(l==r)///递归出口，当左右范围相等时，达到叶子节点，这个范围内等于当前区间范围(单点位置)所存储的值
    {
        a[root].sum=b[l];
    }
    else
    {
        int mid=(l+r)/2;///如果不是递归终点，找出左儿子和右儿子节点的范围，继续往下二分区间
        build(l,mid,root*2);///左儿子，节点为父亲节点*2，范围是l~mid中点
        build(mid+1,r,root*2+1);///右儿子，节点为父亲节点*2+1，范围是mid+1~r
        a[root].sum=a[root*2].sum+a[root*2+1].sum;///这里是建树之处的各个节点存储的总和，父亲节点等于已经建好的两个儿子节点之和
    }
}
void add(int i,int adds,int root)///单点更新(加)
{
    a[root].sum=a[root].sum+adds;///一路从总和更新至叶子节点
    if(a[root].l==i&&i==a[root].r)return;
    if(i>(a[root].l+a[root].r)/2) add(i,adds,root*2+1);
    else add(i,adds,root*2);///从上到下更新
}
void sub(int i,int subs,int root)///单点更新(减)
{
    a[root].sum=a[root].sum-subs;///当前指向的父亲节点内存储的和减去某个节点被减的人数，从最上方的节点一直减到第i个指定的叶子节点
    if(a[root].l==i&&i==a[root].r)return;///直到递归至被减少人数的那个节点(叶子节点)
    if(i>(a[root].l+a[root].r)/2) sub(i,subs,root*2+1);///如果不是叶子节点(当指定营地i的值，大于mid时，找右儿子)，也就是继续递归给下一个节点(右儿子的节点)中存储的和减人数，并继续递归
    else sub(i,subs,root*2);///否则就是左儿子减去相应人数
}
void query(int l,int r,int root)///查询
{
    if(l<=a[root].l&&a[root].r<=r)///当前所查询节点的区间
    {///包含关系，所查询节点区间被包含在目的区间内，记得拿的是查询目的区间和节点的区间相比较，而不是找到叶子节点
        sums=sums+a[root].sum;
    }
    else
    {
        int mid = (a[root].l+a[root].r)/2;///这里是三种情况，当左值(较小值)都大于中点mid，说明完全是在右儿子区间范围的
        if(l>=mid+1)///右儿子
        {
            query(l,r,root*2+1);
        }
        else if(r<=mid)///左儿子
        {///第二种情况，当要查询区间的右值(较大值)都小于中点，说明要找到区间是左儿子范围
            query(l,r,root*2);
        }
        else///第三种情况，当要查询的区间，正好跨越中间两个节点的范围时，将同时向下搜索，这里实际的情况是，l值在表现在左儿子处，r值表现在右儿子处，上面两个条件都不符合，那么将两个儿子同时搜索
        {
            query(l,r,root*2);
            query(l,r,root*2+1);
        }
    }
}
///依据：因为判断条件是==时是刚好卡位，那么必须传参mid，因为不可能有任何一个节点的区间符合要查询的区间
///包含的范围判定比==卡住更具有广泛性，因为同样情况，即使是包含最终实现时也会回到第一次找到符合条件的区间即是==情况
///总结: 情况1：三种情况if else if方法：递归出口采用==卡位：传参时第三种分叉情况必须传参mid和mid+1
///      情况2：三种情况 if else if方法：递归出口采用<=包含：传参可以是mid和mid+1,也可以是传参l r
///      情况3：两种if并行：递归出口采用<=包含：传参必须是l r
int main()
{
    int t;
    scanf("%d",&t);
    int flag=1;
    while(t--)
    {
        int n,i,j;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
        }
        build(1,n,1);///建树
        printf("Case %d:\n",flag++);
        char commed[7];
        while(scanf("%s",commed)!=EOF)
        {
            if(strcmp(commed,"End")==0)///结束判断
            {
                break;
            }
            else if(strcmp(commed,"Add")==0)///单点更新(加)
            {
                scanf("%d%d",&i,&j);
                add(i,j,1);
            }
            else if(strcmp(commed,"Sub")==0)///单点更新(减)
            {
                scanf("%d%d",&i,&j);
                sub(i,j,1);
            }
            else if(strcmp(commed,"Query")==0)///查询
            {
                scanf("%d%d",&i,&j);
                sums=0;///求和初始化
                query(i,j,1);///查询函数
                printf("%d\n",sums);
            }
        }
    }
    return 0;
}
**/
