#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
struct edge {
  int to;
  bool flag;
  edge() {}
  edge(int a, bool b) {
    to = a;
    flag = b;
  }
};
queue<int> q;
vector<edge> mp[maxn];
int t, n;
int r[maxn];
bool vis[maxn];
int finds(int x) { return r[x] == x ? x : r[x] = finds(r[x]); }
void join(int x, int y) {
  int a = finds(x), b = finds(y);
  if (a != b)
    r[b] = a; /// 查了两天的代码，并查集写错了
}
void init() {
  for (int i = 0; i <= n; i++)
    mp[i].clear(), r[i] = i;
  M(vis, false);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    init();
    int son;
    char str[13];
    for (int i = 1; i <= n;
         i++) /// 有指认关系的两者建立有向边，由被指认的人 指向 指认的人
              /// 表示如果被指认的人出现狼了，那么回推，指认其实村民的必然是狼
    {
      scanf("%d%s", &son, str);
      mp[son].pb(edge(i, str[0] == 'w' ? true : false));
      if (str[0] != 'w')
        join(i, son); /// 其中指认为村民的一群人并查集联通成环
    }
    while (!q.empty())
      q.pop();
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < mp[i].size();
           j++) /// 查了两天的代码，for循环写成了i++
      {
        if (finds(mp[i][j].to) == finds(i) && mp[i][j].flag &&
            !vis[i]) /// 遍历出边，当该出边为狼的指认时，且双方在一个村民环中，说明出现矛盾
        {
          ans++; /// 出现矛盾的人就是被指认为狼的人，那么指认其为村民的这个环将全都是村民
          q.push(i);
          vis[i] = true;
        }
      }
    while (
        !q.empty()) /// 对已经确定的，各个环中的狼进行广搜，以排序各个环中可能出现的狼
    {
      int top = q.front();
      q.pop();
      for (int i = 0; i < mp[top].size(); i++) {
        if (mp[top][i].flag || vis[mp[top][i].to])
          continue;
        ans++;
        q.push(mp[top][i].to);
      }
    }
    printf("0 %d\n", ans);
  }
}
/*
999
2
2 werewolf
1 werewolf
3
2 v
1 v
2 w
*/
