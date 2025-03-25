#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int walkx[] = {1, -1, 0, 0};
int walky[] = {0, 0, 1, -1};
struct point {
  int x, y, ans;
  bool operator<(const point &a) const { return ans > a.ans; }
} st, ed;
char ma[208][208];
bool vis[208][208];
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%c", &ma[i][j]);
        if (ma[i][j] == 'Z')
          st.x = i, st.y = j;
        if (ma[i][j] == 'W')
          ed.x = i, ed.y = j;
      }
      getchar();
    }
    priority_queue<point> q;
    while (!q.empty())
      q.pop();
    int ans = 0x7fffffff;
    vis[st.x][st.y] = true;
    st.ans = 0;
    q.push(st);
    bool flag = false;
    while (!q.empty()) {
      point tmp, top = q.top();
      q.pop();
      for (int i = 0; i < 4; i++) {
        tmp.x = top.x + walkx[i];
        tmp.y = top.y + walky[i];
        tmp.ans = top.ans + 1;
        if (ma[tmp.x][tmp.y] >= '0' && ma[tmp.x][tmp.y] <= '9')
          tmp.ans += ma[tmp.x][tmp.y] - '0';
        if (ma[tmp.x][tmp.y] == 'W') {
          ans = tmp.ans;
          flag = true;
          break;
        }
        if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < n && tmp.y < m &&
            !vis[tmp.x][tmp.y] && ma[tmp.x][tmp.y] != '#') {
          vis[tmp.x][tmp.y] = true;
          q.push(tmp);
        }
      }
      if (flag)
        break;
    }
    if (ans == 0x7fffffff)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", ans);
  }
}
