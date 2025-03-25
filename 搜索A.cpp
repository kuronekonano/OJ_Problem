#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int vis[1000];
  int t;
  while (scanf("%d", &t) != EOF) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    while (!q.empty()) {
      q.pop();
    }
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
      int walk = q.front();
      q.pop();
      if (walk - 1 >= 0 && !vis[walk - 1]) {
        q.push(walk - 1);
        vis[walk - 1] = vis[walk] + 1;
      }
      if (walk + 2 < 500 && !vis[walk + 2]) {
        q.push(walk + 2);
        vis[walk + 2] = vis[walk] + 1;
      }
      if (walk * 2 < 500 && !vis[walk * 2]) {
        q.push(walk * 2);
        vis[walk * 2] = vis[walk] + 1;
      }
      if (vis[t]) {
        break;
      }
    }
    printf("%d\n", vis[t] - 1);
  }
  return 0;
}
