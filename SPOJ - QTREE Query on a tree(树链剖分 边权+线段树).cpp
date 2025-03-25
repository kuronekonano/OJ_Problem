#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 1e4 + 10;
struct node {
  int to, val;
  node() {}
  node(int a, int b) {
    to = a;
    val = b;
  }
};
vector<node> mp[maxn];
int n;
int fa[maxn];
int deep[maxn];
int top[maxn];
int son[maxn];
int fp[maxn];
int sum[maxn];
int num[maxn];
int edgeval[maxn];
int pos;
void dfs1(int rt, int pre, int dep, int val) {
  deep[rt] = dep;
  edgeval[rt] = val;
  fa[rt] = pre;
  sum[rt] = 1;
  for (int i = 0; i < mp[rt].size(); i++) {
    int v = mp[rt][i].to;
    if (v != pre) {
      dfs1(v, rt, dep + 1, mp[rt][i].val);
      sum[rt] += sum[v];
      if (son[rt] == 0 || sum[v] > sum[son[rt]])
        son[rt] = v;
    }
  }
}
void dfs2(int rt, int boss) {
  top[rt] = boss;
  num[rt] = ++pos;
  fp[num[rt]] = rt;
  if (son[rt] == 0)
    return;
  dfs2(son[rt], boss);
  for (int i = 0; i < mp[rt].size(); i++) {
    int v = mp[rt][i];
    if (v != son[rt] && v != fa[rt])
      dfs2(v, v);
  }
}
struct node {
  int l, r, val, lazy;
} tre[maxn << 2];
void pushdown(int rt) { if () }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int from, to, val;
    for (int i = 0; i <= n; i++)
      mp[i].clear();
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &from, &to, &val);
      mp[from].push_back(node(to, val));
      mp[to].push_back(node(from, val));
    }
    dfs1(1, 0, 0, 0);
    dfs2(1, 1);
    build()
  }
}
