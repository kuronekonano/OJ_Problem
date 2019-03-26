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
} a[N*4];///һ�㶨Ϊ���ֵ���ı�
int b[50003],sums;///b�洢һ��ʼÿ��Ӫ�ص�������sums�洢����������������
void build(int l,int r,int root)///����
{
    a[root].l=l;///�ӵ�һ���ڵ㿪ʼ�������1���ұ�������n
    a[root].r=r;///֮��ݹ�ʱ��ı�root(�ڵ�)��ֵ�����ÿһ����Χ���ҷ�Χ������Ϊ���뺯���е�lֵ��rֵ
    if(l==r)///�ݹ���ڣ������ҷ�Χ���ʱ���ﵽҶ�ӽڵ㣬�����Χ�ڵ��ڵ�ǰ���䷶Χ(����λ��)���洢��ֵ
    {
        a[root].sum=b[l];
    }
    else
    {
        int mid=(l+r)/2;///������ǵݹ��յ㣬�ҳ�����Ӻ��Ҷ��ӽڵ�ķ�Χ���������¶�������
        build(l,mid,root*2);///����ӣ��ڵ�Ϊ���׽ڵ�*2����Χ��l~mid�е�
        build(mid+1,r,root*2+1);///�Ҷ��ӣ��ڵ�Ϊ���׽ڵ�*2+1����Χ��mid+1~r
        a[root].sum=a[root*2].sum+a[root*2+1].sum;///�����ǽ���֮���ĸ����ڵ�洢���ܺͣ����׽ڵ�����Ѿ����õ��������ӽڵ�֮��
    }
}
void add(int i,int adds,int root)///�������(��)
{
    a[root].sum=a[root].sum+adds;///һ·���ܺ͸�����Ҷ�ӽڵ�
    if(a[root].l==i&&i==a[root].r)return;
    if(i>(a[root].l+a[root].r)/2) add(i,adds,root*2+1);
    else add(i,adds,root*2);///���ϵ��¸���
}
void sub(int i,int subs,int root)///�������(��)
{
    a[root].sum=a[root].sum-subs;///��ǰָ��ĸ��׽ڵ��ڴ洢�ĺͼ�ȥĳ���ڵ㱻���������������Ϸ��Ľڵ�һֱ������i��ָ����Ҷ�ӽڵ�
    if(a[root].l==i&&i==a[root].r)return;///ֱ���ݹ����������������Ǹ��ڵ�(Ҷ�ӽڵ�)
    if(i>(a[root].l+a[root].r)/2) sub(i,subs,root*2+1);///�������Ҷ�ӽڵ�(��ָ��Ӫ��i��ֵ������midʱ�����Ҷ���)��Ҳ���Ǽ����ݹ����һ���ڵ�(�Ҷ��ӵĽڵ�)�д洢�ĺͼ��������������ݹ�
    else sub(i,subs,root*2);///�����������Ӽ�ȥ��Ӧ����
}
void query(int l,int r,int root)///��ѯ
{
    if(l<=a[root].l&&a[root].r<=r)///��ǰ����ѯ�ڵ������
    {///������ϵ������ѯ�ڵ����䱻������Ŀ�������ڣ��ǵ��õ��ǲ�ѯĿ������ͽڵ��������Ƚϣ��������ҵ�Ҷ�ӽڵ�
        sums=sums+a[root].sum;
    }
    else
    {
        int mid = (a[root].l+a[root].r)/2;///�������������������ֵ(��Сֵ)�������е�mid��˵����ȫ�����Ҷ������䷶Χ��
        if(l>=mid+1)///�Ҷ���
        {
            query(l,r,root*2+1);
        }
        else if(r<=mid)///�����
        {///�ڶ����������Ҫ��ѯ�������ֵ(�ϴ�ֵ)��С���е㣬˵��Ҫ�ҵ�����������ӷ�Χ
            query(l,r,root*2);
        }
        else///�������������Ҫ��ѯ�����䣬���ÿ�Խ�м������ڵ�ķ�Χʱ����ͬʱ��������������ʵ�ʵ�����ǣ�lֵ�ڱ���������Ӵ���rֵ�������Ҷ��Ӵ����������������������ϣ���ô����������ͬʱ����
        {
            query(l,r,root*2);
            query(l,r,root*2+1);
        }
    }
}
///���ݣ���Ϊ�ж�������==ʱ�Ǹպÿ�λ����ô���봫��mid����Ϊ���������κ�һ���ڵ���������Ҫ��ѯ������
///�����ķ�Χ�ж���==��ס�����й㷺�ԣ���Ϊͬ���������ʹ�ǰ�������ʵ��ʱҲ��ص���һ���ҵ��������������伴��==���
///�ܽ�: ���1���������if else if�������ݹ���ڲ���==��λ������ʱ�����ֲַ�������봫��mid��mid+1
///      ���2��������� if else if�������ݹ���ڲ���<=���������ο�����mid��mid+1,Ҳ�����Ǵ���l r
///      ���3������if���У��ݹ���ڲ���<=���������α�����l r
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
        build(1,n,1);///����
        printf("Case %d:\n",flag++);
        char commed[7];
        while(scanf("%s",commed)!=EOF)
        {
            if(strcmp(commed,"End")==0)///�����ж�
            {
                break;
            }
            else if(strcmp(commed,"Add")==0)///�������(��)
            {
                scanf("%d%d",&i,&j);
                add(i,j,1);
            }
            else if(strcmp(commed,"Sub")==0)///�������(��)
            {
                scanf("%d%d",&i,&j);
                sub(i,j,1);
            }
            else if(strcmp(commed,"Query")==0)///��ѯ
            {
                scanf("%d%d",&i,&j);
                sums=0;///��ͳ�ʼ��
                query(i,j,1);///��ѯ����
                printf("%d\n",sums);
            }
        }
    }
    return 0;
}
**/
