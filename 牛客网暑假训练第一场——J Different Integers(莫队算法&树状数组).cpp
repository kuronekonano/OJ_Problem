#include<stdio.h>///树状数组
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int inf=1000000007;
struct node
{
    int l,r,id;
}que[maxn];
bool cmp(node a,node b)
{
    return a.r<b.r;
}
int n,q;
int num[maxn];
int first[maxn],last[maxn];
int tree[maxn],ans[maxn];
int lowbit(int x)
{
    return (-x)&x;
}
int updata(int x,int tmp)
{
    for(int i=que[x].l;i<=n;i+=lowbit(i))
        tmp-=tree[i];
    return tmp;
}
void query(int x)
{
    for(int i=x;i>0;i-=lowbit(i))
        tree[i]++;
}
int main()
{
    int cnt=0;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        cnt=0;
        memset(first,-1,sizeof first);
        memset(tree,0,sizeof tree);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            last[num[i]]=i;
            if(first[num[i]]==-1)first[num[i]]=i,cnt++;
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&que[i].l,&que[i].r);
            que[i].id=i;
        }
        sort(que,que+q,cmp);///询问排序，按R右边界从小到大
        int j=0;
        for(int i=1;i<=n;i++)
        {
            while(j<q&&que[j].r==i) ans[que[j].id]=updata(j,cnt),j++;
            if(last[num[i]]==i) query(first[num[i]]-1);
        }
        for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    }
}


/***
#include<bits/stdc++.h>///莫队
using namespace std;
const int maxn=100005;
struct node
{
    int l,r,id;
} que[maxn];
int n,q;
int a[maxn];
int pos[maxn];
int num[maxn];
int L,R;
int ans[maxn];
int cnt=0;
bool cmp(node a,node b)
{
    if(pos[a.l]==pos[b.l])return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
void del(int x)
{
    if(num[a[x]]==0)cnt++;
    num[a[x]]++;
}
void add(int x)
{
    num[a[x]]--;
    if(num[a[x]]==0)cnt--;
}
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        L=1,R=0;
        memset(num,0,sizeof num);
        int sz=1000;
        cnt=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            pos[i]=i/sz;
            if(num[a[i]]==0)cnt++;
            num[a[i]]++;
        }
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d",&que[i].l,&que[i].r);
            que[i].l++,que[i].r--;
            que[i].id=i;
        }
        sort(que+1,que+1+q,cmp);
        for(int i=1; i<=q; i++)
        {
            while(L<que[i].l) del(L),L++;
            while(L>que[i].l) L--,add(L);
            while(R<que[i].r) add(++R);
            while(R>que[i].r) del(R--);
            ans[que[i].id]=cnt;
        }
        for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    }
}
/*
3 3
1 2 1
1 2
1 3
2 2
4 1
1 2 3 4
1 3
*/
/***
