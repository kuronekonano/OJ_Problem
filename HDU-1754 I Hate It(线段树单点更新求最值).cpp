#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 2e5 + 8;
struct node {
  int l, r, ma;
} tre[maxn << 2];
int n, m, a[maxn];
void push_up(int rt) { tre[rt].ma = max(tre[rt << 1].ma, tre[rt << 1 | 1].ma); }
void build(int l, int r, int rt) {
  tre[rt].l = l;
  tre[rt].r = r;
  if (l == r)
    tre[rt].ma = a[l];
  else {
    int mid = (r + l) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
  }
}
void update(int pos, int val, int rt) {
  if (tre[rt].l == pos && tre[rt].r == pos)
    tre[rt].ma = val;
  else {
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (pos > mid)
      update(pos, val, rt << 1 | 1);
    else if (pos <= mid)
      update(pos, val, rt << 1);
    push_up(rt);
  }
}
int query(int l, int r, int rt) {
  if (tre[rt].l >= l && tre[rt].r <= r)
    return tre[rt].ma;
  else {
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (l > mid)
      return query(l, r, rt << 1 | 1);
    else if (r <= mid)
      return query(l, r, rt << 1);
    else
      return max(query(l, r, rt << 1 | 1), query(l, r, rt << 1));
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    build(1, n, 1);
    char com[3];
    int l, r, val;
    while (m--) {
      scanf("%s", com);
      if (com[0] == 'Q') {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r, 1));
      } else {
        scanf("%d%d", &l, &val);
        update(l, val, 1);
      }
    }
  }
}

/**
#include<stdio.h>///ȡ���ֵ
#include<string.h>
#include<algorithm>
#define N 200000
using namespace std;
struct tree
{
    int l,r,maxx;
} a[N*4];///�ı���ԭ�����ֵ
int b[200003];///�洢ÿ�˳ɼ�������
void build(int l,int r,int root)///����
{
    a[root].l=l;///���ҷ�Χ��ֵ
    a[root].r=r;
    a[root].maxx=-1;///���ֵ��ʼ��
    if(l==r)///Ҷ�ӽڵ㱻��������ɼ�
    {
        a[root].maxx=b[l];
    }
    else///����Ҷ�ӽڵ��������
    {
        int mid=(l+r)/2;///�е�
        build(l,mid,root*2);///�����
        build(mid+1,r,root*2+1);///�Ҷ���        �ݹ齨��
        a[root].maxx=max(a[root*2].maxx,a[root*2+1].maxx);///�ݹ���ɺ�ȡ���õ����еĵײ�һ�������ϴ���ȡ��ֵ
    }
}
void upda(int where , int value , int root)///�������
{
    if(a[root].l == a[root].r)///��Ҫ���µ�Ҷ�ӽڵ�
    {
        a[root].maxx = value ;
        return ;///�ݹ��յ�
    }
    int mid = (a[root].l+a[root].r)/2
;///�������ǵݹ�����ˣ����仰˵�����꽨�����ºͲ�����ʵ�����������
    if(where<=mid) upda(where,value,root*2);///��Ŀ������С���е㣬�����������
    else upda(where,value,root*2+1);///�������Ҷ�������
    a[root].maxx = max(a[root*2].maxx ,
a[root*2+1].maxx);///�Ѿ��������ϴ��ݵĲ���
}///�������ϵݹ鷵�ظ���
//void pushup(int root)///���ϴ���
//{
//    if(a[root].l==a[root].r)return;
//    a[root].maxx=max(a[root*2].maxx,a[root*2+1].maxx);
//}

int query(int l,int r,int root)///�����ѯ
{
    if(l<=a[root].l&&a[root].r<=r)///�ڰ��������ڲ�ѯ��Ŀ������
    {
        return a[root].maxx;
    }
    else
    {
        int mid = (a[root].l+a[root].r)/2;
        int res=-1;///��ʼ����ֵ��¼
        if(l<=mid)
        {
            res =
max(query(l,r,root*2),res);///��ѯʱע��Ŀ�����䲻Ҫ�ı䣬�μ���mid+1��mid�Ǹı��˵ģ���WA
        }
        if(r>=mid+1)
        {
            res = max(query(l,r,root*2+1),res);
        }
        return res;///�������ֵ
    }
}
int main()
{
    int n,i,j,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1; i<=n; i++)///����ÿ�˳ɼ�
        {
            scanf("%d",&b[i]);
        }
        build(1,n,1);///����
//        for(i=1; i<=n; i++)
//        {
//            printf("=====\n");
//            printf("%d\n",a[i].maxx);
//        }
        char commed[2];///ָ�Ϊ��ֹgetchar������������
        while(m--)
        {
            scanf("%s",commed);
            if(commed[0]=='U')///����ָ��
            {
                scanf("%d%d",&i,&j);
                upda(i,j,1);
//                pushup(1);
//                for(i=1; i<=n; i++)
//                {
//                    printf("=====\n");
//                    printf("%d\n",a[i].maxx);
//                }
            }
            else if(commed[0]=='Q')///��ѯָ��
            {
                scanf("%d%d",&i,&j);
                int maxy=query(i,j,1);
                printf("%d\n",maxy);
            }
        }
    }
    return 0;
}
**/
