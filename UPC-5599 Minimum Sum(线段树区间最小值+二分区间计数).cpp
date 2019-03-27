#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node
{
    int l,r,minn;
} tree[200005*4];
int a[200004],n,mp[200005];
LL ans;
void build(int l,int r,int rt)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].minn=0x7fffffff;
    if(l==r) tree[rt].minn=a[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        tree[rt].minn=min(tree[rt<<1].minn,tree[rt<<1|1].minn);

    }
}
int query(int l,int r,int rt)
{
    if(l<=tree[rt].l&&tree[rt].r<=r) return tree[rt].minn;
    else
    {
        int mid=(tree[rt].l+tree[rt].r)>>1;
        int minn=0x7fffffff;
        if(l<=mid) minn=min(query(l,r,rt<<1),minn);
        if(r>=mid+1) minn=min(query(l,r,rt<<1|1),minn);
        return minn;
    }
}
void dfs(int l,int r)
{
    if(r<l) return;
    int mini=mp[query(l,r,1)];
//    printf("%d===%d==%d\n",l,mini,r);
    ans+=(LL)(mini-l+1)*(LL)(r-mini+1)*(LL)a[mini];
    dfs(l,mini-1);
    dfs(mini+1,r);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(int i=1; i<=n; i++) scanf("%d",&a[i]),mp[a[i]]=i;
        build(1,n,1);
        dfs(1,n);
        printf("%lld\n",ans);
    }
}
