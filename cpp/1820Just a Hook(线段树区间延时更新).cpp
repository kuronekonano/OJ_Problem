#include <stdio.h>
#include <string.h>
const int N = 100010;
int n, m, k;
struct node {
  int l, r, sum;
  int mark;
} tree[N << 2];

void build(int rt, int l, int r) {
  tree[rt].l = l;
  tree[rt].r = r;
  tree[rt].mark = 0; /// 注意mark延时标记的初始化位置
  if (l == r) {
    tree[rt].sum = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  return;
}

void pushdown(int rt) {
  if (tree[rt].mark) {
    tree[rt << 1 | 1].sum =
        (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) *
        tree[rt].mark; /// 这里的push_down是直接赋值，而非增加
    tree[rt << 1].sum = (tree[rt << 1].r - tree[rt << 1].l + 1) * tree[rt].mark;
    tree[rt << 1 | 1].mark = tree[rt].mark;
    tree[rt << 1].mark = tree[rt].mark;
    tree[rt].mark = 0;
  }
  return;
}
void update(int rt, int l, int r, int val) {
  if (tree[rt].l >= l && tree[rt].r <= r) {
    tree[rt].sum = (tree[rt].r - tree[rt].l + 1) * val;
    tree[rt].mark = val;
    return;
  }
  pushdown(rt);
  int mid = (tree[rt].l + tree[rt].r) >> 1;
  if (l <= mid)
    update(rt << 1, l, r, val);
  if (r > mid)
    update(rt << 1 | 1, l, r, val);
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  return;
}

int query(int rt, int l, int r) {
  int ans = 0;
  if (tree[rt].l >= l && tree[rt].r <= r)
    return tree[rt].sum;
  pushdown(rt);
  int mid = (tree[rt].l + tree[rt].r) >> 1;
  if (l <= mid)
    ans += query(rt << 1, l, r);
  if (r > mid)
    ans += query(rt << 1 | 1, l, r);
  return ans;
}

int main() {
  int ca = 0, t, l, r, val;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while (m--) {
      scanf("%d%d%d", &l, &r, &val);
      update(1, l, r, val);
    }
    printf("Case %d: The total value of the hook is %d.\n", ++ca,
           query(1, 1, n));
  }
  return 0;
}

// #include<stdio.h>
// #define N 100000
// struct tree
//{
//     int l,r,n;
// } a[N*4];
// void build(int l,int r,int root)
//{
//     a[root].l=l;
//     a[root].r=r;
//     a[root].n=1;///树中存储的便是Mark历史记录数组(此处全部初始化为1，都是铜色)
//     if(a[root].l!=a[root].r)///递归建树
//     {
//         int mid=(l+r)/2;
//         build(l,mid,root*2);
//         build(mid+1,r,root*2+1);
//     }
// }
// void upda(int i,int l,int r,int root)
//{
//     if(a[root].n==i)///颜色一样不用修改(好像这是用来省时的，遇到一样的大区间，那么对应的目的区间一定是指定颜色，相应的也不用深入查找修改了)
//     {
//         return;
//     }
//     if(a[root].l>=l&&a[root].r<=r)///找到区间立即修改(递归出口)
//     {
//         a[root].n=i;
//         return;
//     }
//     if(a[root].n!=-1)///若没有找到对应区间，切还在上层查找区间，那么在正在遍历的这个大区间里，其颜色一定是要被修改的，也就是说他其实是杂色，如果作为杂色还没有被标记为-1
//     {
//         a[root*2].n=a[root*2+1].n=a[root].n;///将此区间原色的标记传递给两个儿子
//         a[root].n=-1;///父亲被标记为杂色，儿子继承父亲的原颜色
//     }
//     int
//     mid=(a[root].l+a[root].r)/2;///查找的是当前节点的中点，而不是目的区间的中点
//     if(l>mid)
//     {
//         upda(i,l,r,root*2+1);///右儿子
//     }
//     else if(r<=mid)
//     {
//         upda(i,l,r,root*2);///左儿子
//     }
//     else
//     {
//         upda(i,l,r,root*2);///事实证明，我这里因为使用包含区间了，因此传参传递l和r也是可以的
//         upda(i,l,r,root*2+1);
//     }
// }
// int query(int root)///这里不是查询区间了，这里是求总和，不需要区间判断了
//{
//     if(a[root].n!=-1)///遇到同色时便是可以一起求和的区间块了，并返回这块颜色相同的块的和
//     {///果然是要加一，计算的是长度，不是距离，因此要算上被减数的本身
//         return (a[root].r-a[root].l+1)*a[root].n;///利用mark
//         数组，已经对应区间的距离求和
//     }///找同样区间的区域块，省时
//     return
//     query(root*2)+query(root*2+1);///左右两棵树作为杂色的两部分继续查找同色区间
//
// }
// int main()
//{
//     int t,flag=1;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int num,q;
//         scanf("%d%d",&num,&q);
//         build(1,num,1);///建树
//         while(q--)///更新
//         {
//             int x,y,z;
//             scanf("%d%d%d",&x,&y,&z);
//             upda(z,x,y,1);///更新
//         }
////        for(int i=1;i<=num;i++)
////        {
////            printf("%d\n",a[i].n);
////        }
//        printf("Case %d: The total value of the hook is
//        %d.\n",flag++,query(1));///查询求和
//    }
//    return 0;
//}
