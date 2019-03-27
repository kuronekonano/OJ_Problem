#include<bits/stdc++.h>
#define M(a,b) memset(a,b,sizeof a)
#define LL long long
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e6+7;
const int inf=-10000;
int n,m,q;
LL b[maxn];
struct num
{
    int pos,val;
} a[maxn],s[maxn];
struct node
{
    int l,r;
    LL ma;
} tre[maxn<<2];
void push_up(int rt)
{
    tre[rt].ma=min(tre[rt<<1].ma,tre[rt<<1|1].ma);
}
void build(int l,int r,int rt)
{
    tre[rt].l=l,tre[rt].r=r;
    if(l==r)tre[rt].ma=b[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        push_up(rt);
    }
}
LL rmq(int l,int r,int rt)
{
    if(tre[rt].l>=l&&tre[rt].r<=r)return tre[rt].ma;
    else
    {
        int mid=(tre[rt].l+tre[rt].r)>>1;
        if(l>mid)return rmq(l,r,rt<<1|1);
        else if(r<=mid)return rmq(l,r,rt<<1);
        else return min(rmq(l,r,rt<<1|1),rmq(l,r,rt<<1));
    }
}
int main()
{
    int head=0;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i].val);
        a[i].pos=i;
        if(head&&((s[head-1].val^1)==a[i].val&&s[head-1].val<a[i].val)) b[s[head-1].pos]=1,b[i]=-1,head--;
        else s[head]=a[i],head++;
    }
    while(head>0)
    {
        b[s[head-1].pos]=inf;
        head--;
    }
    b[0]=0;
    for(int i=2; i<=n; i++)b[i]+=b[i-1];
    build(1,n,1);
    int l,r;
    while(q--)
    {
        scanf("%d%d",&l,&r);
        printf("%s\n",rmq(l,r,1)-b[l-1]>=0&&b[r]-b[l-1]==0&&l!=r?"Yes":"No");
    }
}
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
using namespace std;
const int MAXN=1000006;

vector<int> sta;
int pos[MAXN];
int a[MAXN];

int main(){

    int N,M,Q;
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=N;i++){
        if(sta.empty())
            sta.push_back(i);
        else if(a[i]/2==a[sta.back()]/2&&a[i]==a[sta.back()]+1)
            sta.pop_back();
        else
            sta.push_back(i);
        if(!sta.empty())
            pos[i]=sta.back();
    }
    int l,r;
    while(Q--){
        scanf("%d%d",&l,&r);
        if(pos[r]==pos[l-1])
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
