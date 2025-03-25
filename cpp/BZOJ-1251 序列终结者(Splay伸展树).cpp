#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x7fffffff;
struct Splay_tree {
  int root, fa[maxn];
  struct node {
    int val, maxx, add, siz, son[2];
    bool rev;
    void init(int x) {
      val = maxx = x;
      siz = 1;
      add = rev = son[0] = son[1] = 0;
    }
  } tre[maxn];
  void pushup(int x) /// 向上传递
  {
    tre[x].maxx = tre[x].val;
    tre[x].siz = 1;
    if (tre[x].son[0]) {
      tre[x].maxx = max(tre[x].maxx, tre[tre[x].son[0]].maxx);
      tre[x].siz += tre[tre[x].son[0]].siz;
    }
    if (tre[x].son[1]) {
      tre[x].maxx = max(tre[x].maxx, tre[tre[x].son[1]].maxx);
      tre[x].siz += tre[tre[x].son[1]].siz;
    }
  }
  void pushdown(int x) /// 向下传递
  {
    if (x == 0)
      return;
    if (tre[x].add) {
      if (tre[x].son[0]) {
        tre[tre[x].son[0]].val += tre[x].add;
        tre[tre[x].son[0]].maxx += tre[x].add;
        tre[tre[x].son[0]].add += tre[x].add;
      }
      if (tre[x].son[1]) {
        tre[tre[x].son[1]].val += tre[x].add;
        tre[tre[x].son[1]].maxx += tre[x].add;
        tre[tre[x].son[1]].add += tre[x].add;
      }
      tre[x].add = 0;
    }
    if (tre[x].rev) {
      if (tre[x].son[0])
        tre[tre[x].son[0]].rev ^= 1;
      if (tre[x].son[1])
        tre[tre[x].son[1]].rev ^= 1;
      swap(tre[x].son[0], tre[x].son[1]);
      tre[x].rev = 0;
    }
  }
  void rota(int x, int kind) /// 旋转
  {
    int y = fa[x], z = fa[y];

    tre[y].son[!kind] = tre[x].son[kind];
    fa[tre[x].son[kind]] = y;

    tre[x].son[kind] = y;
    fa[y] = x;

    tre[z].son[tre[z].son[1] == y] = x;
    fa[x] = z;

    pushup(y);
  }
  //    void zig(int x)///右旋
  //    {
  //        int y=fa[x];
  //        ch[y][0]=ch[x][1];
  //        fa[ch[x][1]]=y;
  //        ch[x][1]=y;
  //        fa[x]=fa[y];
  //        if(y==ch[fa[y]][0]) ch[fa[y]][1]=x;
  //        else if(y==ch[fa[y]][1]) ch[fa[y]][1]=x;
  //    }
  //
  //    void zag(int x)///左旋
  //    {
  //        int y=fa[x];
  //        ch[y][1]=ch[x][0];
  //        fa[ch[x][0]]=y;
  //        ch[x][0]=y;
  //        fa[x]=fa[y];
  //        if(y==ch[fa[y]][0])
  //            ch[fa[y]][0]=x;
  //        else if(y==ch[fa[y]][1])
  //            ch[fa[y]][1]=x;
  //        fa[y]=x;
  //        pushup(y);
  //        if(y==root)root=x;
  //    }
  void Splay(int x, int goal) {
    if (x == goal)
      return;
    while (fa[x] != goal) {
      int y = fa[x], z = fa[y];
      pushdown(z);
      pushdown(y);
      pushdown(x);
      int rx = tre[y].son[0] == x, ry = tre[z].son[0] == y;
      if (z == goal)
        rota(x, rx);
      else {
        if (rx == ry)
          rota(y, ry);
        else
          rota(x, rx);
        rota(x, ry);
      }
    }
    pushup(x);
    if (goal == 0)
      root = x;
  }

  int select(int pos) {
    int u = root;
    pushdown(u);
    while (tre[tre[u].son[0]].siz != pos) {
      if (pos < tre[tre[u].son[0]].siz)
        u = tre[u].son[0];
      else
        pos -= tre[tre[u].son[0]].siz + 1, u = tre[u].son[1];
      pushdown(u);
    }
    return u;
  }

  void updata(int L, int R, int val) /// 区间更新
  {
    int u = select(L - 1), v = select(R + 1);
    Splay(u, 0);
    Splay(v, u);
    tre[tre[v].son[0]].maxx += val;
    tre[tre[v].son[0]].val += val;
    tre[tre[v].son[0]].add += val;
  }
  void reverse(int L, int R) /// 翻转区间
  {
    int u = select(L - 1), v = select(R + 1);
    Splay(u, 0);
    Splay(v, u);
    tre[tre[v].son[0]].rev ^= 1;
  }
  int query(int L, int R) /// 区间查询
  {
    int u = select(L - 1), v = select(R + 1);
    Splay(u, 0);
    Splay(v, u);
    return tre[tre[v].son[0]].maxx;
  }

  int build(int L, int R) {
    if (L > R)
      return 0;
    if (L == R)
      return L;
    int mid = (L + R) >> 1, sL, sR;
    tre[mid].son[0] = sL = build(L, mid - 1);
    tre[mid].son[1] = sR = build(mid + 1, R);
    fa[sL] = fa[sR] = mid;
    pushup(mid);
    return mid;
  }
  void init(int n) /// 初始化
  {
    tre[0].init(-inf);
    tre[1].init(-inf);
    tre[n + 2].init(-inf);
    for (int i = 2; i <= n + 1; i++)
      tre[i].init(0);
    root = build(1, n + 2), fa[root] = 0;
    fa[0] = 0;
    tre[0].siz = 0;
    tre[0].son[1] = root;
  }
};
Splay_tree a;
int main() {
  int n, m, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    a.init(n);
    int l, r, val;
    while (m--) {
      scanf("%d", &k);
      if (k == 1) {
        scanf("%d%d%d", &l, &r, &val);
        a.updata(l, r, val);
      } else if (k == 2) {
        scanf("%d%d", &l, &r);
        a.reverse(l, r);
      } else {
        scanf("%d%d", &l, &r);
        printf("%d\n", a.query(l, r));
      }
    }
  }
}
