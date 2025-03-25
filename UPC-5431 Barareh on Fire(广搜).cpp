#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, ti;
  node() {};
  node(int a, int b, int c) {
    x = a;
    y = b;
    ti = c;
  }
};
int walkx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int walky[] = {1, 0, -1, 0, -1, 1, 1, -1};
int px[] = {1, -1, 0, 0};
int py[] = {0, 0, 1, -1};
int n, m, k;
char mp[105][105];
int fire[108][108];
bool vis[108][108];
queue<node> q;
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    if (n == 0 && m == 0 && k == 0)
      break;
    node st, ed;
    while (!q.empty())
      q.pop();
    memset(fire, 0x3f, sizeof(fire));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
      scanf("%s", mp[i]);
      for (int j = 0; j < m; j++) {
        if (mp[i][j] == 's')
          st.x = i, st.y = j, st.ti = 0;
        if (mp[i][j] == 't')
          ed.x = i, ed.y = j, ed.ti = 0x3f3f3f3f;
        if (mp[i][j] == 'f') {
          fire[i][j] = 0;
          q.push(node(i, j, 0));
          vis[i][j] = true;
        }
      }
    }
    while (!q.empty()) {
      node tmp = q.front();
      q.pop();
      for (int i = 0; i < 8; i++) {
        int tx = tmp.x + walkx[i];
        int ty = tmp.y + walky[i];
        if (tx >= 0 && ty >= 0 && tx < n && ty < m && vis[tx][ty] == false) {
          fire[tx][ty] = min(fire[tx][ty], tmp.ti + k);
          q.push(node(tx, ty, tmp.ti + k));
          vis[tx][ty] = true;
        }
      }
    }
    //        for(int i=0;i<n;i++)
    //            for(int j=0;j<m;j++)
    //            printf("%d%c",fire[i][j],j==m-1?'\n':' ');
    memset(vis, false, sizeof(vis));
    q.push(st);
    vis[st.x][st.y] = true;
    while (!q.empty()) {
      node tmp = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int tx = tmp.x + px[i];
        int ty = tmp.y + py[i];
        if (tx >= 0 && ty >= 0 && tx < n && ty < m &&
            tmp.ti + 1 < fire[tx][ty] && vis[tx][ty] == false) {
          if (tx == ed.x && ty == ed.y)
            ed.ti = min(ed.ti, tmp.ti + 1);
          q.push(node(tx, ty, tmp.ti + 1));
          vis[tx][ty] = true;
        }
      }
      if (vis[ed.x][ed.y])
        break;
    }
    if (ed.ti == 0x3f3f3f3f)
      printf("Impossible\n");
    else
      printf("%d\n", ed.ti);
  }
}
