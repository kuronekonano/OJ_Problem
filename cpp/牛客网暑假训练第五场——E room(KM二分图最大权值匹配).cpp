#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn], ny, nx;
int n, a[maxn][4], b[maxn][4];
int linker[maxn], lx[maxn], ly[maxn]; /// y中各点匹配状态，x,y中的点标号
int slack[maxn];
bool visx[maxn], visy[maxn];
bool DFS(int x) {
  visx[x] = true;              /// 标记询问过
  for (int y = 0; y < ny; y++) /// 查询一个x能匹配的所有y
  {
    if (visy[y])
      continue; /// 已经标记过的不能再查询
    int tmp = lx[x] + ly[y] - g[x][y];
    if (tmp == 0) /// 相等才能匹配
    {
      visy[y] = true;
      if (linker[y] == -1 ||
          DFS(linker[y])) /// 判断y点是否被匹配过，或是否y点的匹配能找到增广路
      {
        linker[y] = x; /// y点匹配x点
        return true;   /// 增广路查找成功
      }
    } else if (slack[y] > tmp) /// 増广失败，更新记录最小到达y点的d值
      slack[y] = tmp;
  }
  return false;
}
int KM() {
  memset(linker, -1, sizeof(linker));
  memset(ly, 0, sizeof(ly));
  for (int i = 0; i < nx; i++) {
    lx[i] = -INF;
    for (int j = 0; j < ny; j++)
      if (g[i][j] > lx[i])
        lx[i] = g[i][j];
  }
  for (int x = 0; x < nx; x++) {
    for (int i = 0; i < ny; i++)
      slack[i] = INF;
    while (true) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if (DFS(x))
        break; /// 找到增广路
      int d = INF;
      for (int i = 0; i < ny; i++) /// 在剩余未匹配的y节点
        if (!visy[i] && d > slack[i])
          d = slack[i];
      for (int i = 0; i < nx; i++)
        if (visx[i])
          lx[i] -= d;
      for (int i = 0; i < ny; i++) {
        if (visy[i])
          ly[i] += d;
        else
          slack[i] -= d;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < ny; i++)
    if (linker[i] != -1)
      res += g[linker[i]][i];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++)
      scanf("%d", &b[i][j]);
    for (int j = 0; j < n; j++) {
      int val = 0;
      for (int k = 0; k < 4;
           k++) /// 两寝室间一样的人数做计数，作为比较的两个寝室之间的权值
      {
        if (b[i][k] == a[j][0])
          val++;
        if (b[i][k] == a[j][1])
          val++;
        if (b[i][k] == a[j][2])
          val++;
        if (b[i][k] == a[j][3])
          val++;
      }
      g[i][j] = val; /// 要保证走到人最少即留的人最多，那么就是最大权值匹配问题
    }
  }
  nx = ny = n;
  int sum = KM();
  int ans = n * 4 - sum;
  printf("%d\n", ans);
}
