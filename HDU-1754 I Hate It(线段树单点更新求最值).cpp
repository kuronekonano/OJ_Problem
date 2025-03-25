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
#include<stdio.h>///取最大值
#include<string.h>
#include<algorithm>
#define N 200000
using namespace std;
struct tree
{
    int l,r,maxx;
} a[N*4];///四倍的原题最大值
int b[200003];///存储每人成绩的数组
void build(int l,int r,int root)///建树
{
    a[root].l=l;///左右范围赋值
    a[root].r=r;
    a[root].maxx=-1;///最大值初始化
    if(l==r)///叶子节点被赋予数组成绩
    {
        a[root].maxx=b[l];
    }
    else///不是叶子节点继续二分
    {
        int mid=(l+r)/2;///中点
        build(l,mid,root*2);///左儿子
        build(mid+1,r,root*2+1);///右儿子        递归建树
        a[root].maxx=max(a[root*2].maxx,a[root*2+1].maxx);///递归完成后取建好的数中的底层一步步向上传递取最值
    }
}
void upda(int where , int value , int root)///单点更新
{
    if(a[root].l == a[root].r)///需要更新的叶子节点
    {
        a[root].maxx = value ;
        return ;///递归终点
    }
    int mid = (a[root].l+a[root].r)/2
;///这里又是递归更新了，换句话说，尼玛建树更新和查找其实都有这个步骤
    if(where<=mid) upda(where,value,root*2);///当目的区间小于中点，向左儿子搜索
    else upda(where,value,root*2+1);///否则向右儿子搜索
    a[root].maxx = max(a[root*2].maxx ,
a[root*2+1].maxx);///已经有了向上传递的操作
}///由下至上递归返回更新
//void pushup(int root)///向上传递
//{
//    if(a[root].l==a[root].r)return;
//    a[root].maxx=max(a[root*2].maxx,a[root*2+1].maxx);
//}

int query(int l,int r,int root)///区间查询
{
    if(l<=a[root].l&&a[root].r<=r)///在包含区间内查询到目的区间
    {
        return a[root].maxx;
    }
    else
    {
        int mid = (a[root].l+a[root].r)/2;
        int res=-1;///初始化最值记录
        if(l<=mid)
        {
            res =
max(query(l,r,root*2),res);///查询时注意目标区间不要改变，课件中mid+1与mid是改变了的，会WA
        }
        if(r>=mid+1)
        {
            res = max(query(l,r,root*2+1),res);
        }
        return res;///返回最大值
    }
}
int main()
{
    int n,i,j,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1; i<=n; i++)///输入每人成绩
        {
            scanf("%d",&b[i]);
        }
        build(1,n,1);///建树
//        for(i=1; i<=n; i++)
//        {
//            printf("=====\n");
//            printf("%d\n",a[i].maxx);
//        }
        char commed[2];///指令，为防止getchar情况而设成数组
        while(m--)
        {
            scanf("%s",commed);
            if(commed[0]=='U')///更新指令
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
            else if(commed[0]=='Q')///查询指令
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
