#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e6 + 7;
int tri[maxn][26], tot = 0;
vector<int> mp[maxn];
void insert(char a[], int rt) {
  int len = strlen(a);
  vector<int> q;
  for (int i = 0; i < len; i++) {
    int x = a[i] - 'a';
    if (!tri[rt][x]) {
      tri[rt][x] = ++tot;
      M(tri[tot], 0);
      if (i < len - 2)
        q.pb(tot);
      mp[rt].pb(tot);
      mp[tot].pb(rt);
    }
    rt = tri[rt][x];
  }
  for (int i = 0; i < q.size(); i++)
    mp[q[i]].pb(rt);
}
int dis[maxn];
void bfs() {
  queue<int> q;
  q.push(1);
  dis[1] = 0;
  while (!q.empty()) {
    int tp = q.front();
    q.pop();
    for (int i = 0; i < mp[tp].size(); i++) {
      if (!dis[mp[tp][i]]) {
        dis[mp[tp][i]] = dis[tp] + 1;
        q.push(mp[tp][i]);
      }
    }
  }
}
int finds(char a[], int rt) {
  int len = strlen(a), cnt = 0;
  for (int i = 0; i < len; i++) {
    int x = a[i] - 'a';
    if (!tri[rt][x])
      break;
    rt = tri[rt][x];
    cnt++;
  }
  return min(len, len - cnt + dis[rt]);
}
int n, q;
char str[maxn];
int main() {
  int rt = ++tot;
  M(tri[rt], 0);
  M(dis, 0);
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    insert(str, rt);
  }
  bfs();
  while (q--) {
    scanf("%s", str);
    printf("%d\n", finds(str, rt));
  }
}
