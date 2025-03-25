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
  tree[rt].mark = 0; /// ע��mark��ʱ��ǵĳ�ʼ��λ��
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
        tree[rt].mark; /// �����push_down��ֱ�Ӹ�ֵ����������
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
//     a[root].n=1;///���д洢�ı���Mark��ʷ��¼����(�˴�ȫ����ʼ��Ϊ1������ͭɫ)
//     if(a[root].l!=a[root].r)///�ݹ齨��
//     {
//         int mid=(l+r)/2;
//         build(l,mid,root*2);
//         build(mid+1,r,root*2+1);
//     }
// }
// void upda(int i,int l,int r,int root)
//{
//     if(a[root].n==i)///��ɫһ�������޸�(������������ʡʱ�ģ�����һ���Ĵ����䣬��ô��Ӧ��Ŀ������һ����ָ����ɫ����Ӧ��Ҳ������������޸���)
//     {
//         return;
//     }
//     if(a[root].l>=l&&a[root].r<=r)///�ҵ����������޸�(�ݹ����)
//     {
//         a[root].n=i;
//         return;
//     }
//     if(a[root].n!=-1)///��û���ҵ���Ӧ���䣬�л����ϲ�������䣬��ô�����ڱ�������������������ɫһ����Ҫ���޸ĵģ�Ҳ����˵����ʵ����ɫ�������Ϊ��ɫ��û�б����Ϊ-1
//     {
//         a[root*2].n=a[root*2+1].n=a[root].n;///��������ԭɫ�ı�Ǵ��ݸ���������
//         a[root].n=-1;///���ױ����Ϊ��ɫ�����Ӽ̳и��׵�ԭ��ɫ
//     }
//     int
//     mid=(a[root].l+a[root].r)/2;///���ҵ��ǵ�ǰ�ڵ���е㣬������Ŀ��������е�
//     if(l>mid)
//     {
//         upda(i,l,r,root*2+1);///�Ҷ���
//     }
//     else if(r<=mid)
//     {
//         upda(i,l,r,root*2);///�����
//     }
//     else
//     {
//         upda(i,l,r,root*2);///��ʵ֤������������Ϊʹ�ð��������ˣ���˴��δ���l��rҲ�ǿ��Ե�
//         upda(i,l,r,root*2+1);
//     }
// }
// int query(int root)///���ﲻ�ǲ�ѯ�����ˣ����������ܺͣ�����Ҫ�����ж���
//{
//     if(a[root].n!=-1)///����ͬɫʱ���ǿ���һ����͵�������ˣ������������ɫ��ͬ�Ŀ�ĺ�
//     {///��Ȼ��Ҫ��һ��������ǳ��ȣ����Ǿ��룬���Ҫ���ϱ������ı���
//         return (a[root].r-a[root].l+1)*a[root].n;///����mark
//         ���飬�Ѿ���Ӧ����ľ������
//     }///��ͬ�����������飬ʡʱ
//     return
//     query(root*2)+query(root*2+1);///������������Ϊ��ɫ�������ּ�������ͬɫ����
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
//         build(1,num,1);///����
//         while(q--)///����
//         {
//             int x,y,z;
//             scanf("%d%d%d",&x,&y,&z);
//             upda(z,x,y,1);///����
//         }
////        for(int i=1;i<=num;i++)
////        {
////            printf("%d\n",a[i].n);
////        }
//        printf("Case %d: The total value of the hook is
//        %d.\n",flag++,query(1));///��ѯ���
//    }
//    return 0;
//}
