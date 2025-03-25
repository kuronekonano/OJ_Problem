#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 1e3 + 10;
int n, m, w;
char str[maxn][15];
short int mp[maxn][maxn];
int dis(char a[], char b[]) {
  int sum = 0;
  for (int i = 0; i < m; i++)
    if (a[i] != b[i])
      sum++;
  return sum;
}
int prim() {
  bool vis[maxn];
  int dist[maxn];
  memset(vis, false, sizeof(vis));
  memset(dist, 0x7f, sizeof(dist));
  vis[0] = true;
  int minn, mini, sum = 0;
  for (int i = 1; i < n; i++)
    dist[i] = mp[0][i];
  for (int i = 1; i < n; i++) {
    int minn = 0x7fffffff;
    int mini = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && dist[j] < minn) {
        minn = dist[j];
        mini = j;
      }
    }
    sum += minn;
    vis[mini] = true;
    for (int j = 0; j < n; j++)
      if (!vis[j] && mp[mini][j] < dist[j])
        dist[j] = mp[mini][j];
  }
  return sum;
}
int main() {
  while (scanf("%d%d%d", &n, &m, &w) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      for (int j = 0; j < i; j++) {
        int tmp = dis(str[i], str[j]) * w;
        mp[i][j] = mp[j][i] = tmp > m ? m : tmp;
      }
    }
    printf("%d\n", prim() + m);
  }
}
