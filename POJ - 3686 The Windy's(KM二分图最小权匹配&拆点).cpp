/**【求二分图的最小匹配】
只需把权值取反，变为负的，再用KM算出最大权匹配，取反则为其最小权匹配。
**/
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;
int nx, ny;                            /// 两边的点数
int g[N][N * 50];                      /// 二分图描述
int linker[N * 50], lx[N], ly[N * 50]; /// y中各点匹配状态，x,y中的点标号
int slack[N * 50];
bool visx[N], visy[N * 50];
bool DFS(int x) {
  visx[x] = true;               /// 标记询问过
  for (int y = 1; y <= ny; y++) /// 查询一个x能匹配的所有y
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
  memset(ly, 0, sizeof(ly)); /// 初始化右节点权值，开始都是0
  for (int i = 1; i <= nx; i++) {
    lx[i] = -INF;
    for (int j = 1; j <= ny; j++)
      if (g[i][j] > lx[i]) /// lx[i]取最大边权
        lx[i] = g[i][j];
  }
  for (int x = 1; x <= nx; x++) /// 匹配n个节点
  {
    for (int i = 0; i <= ny; i++)
      slack[i] = INF;
    while (true) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if (DFS(x))
        break; /// 找到增广路
      int d = INF;
      for (int i = 1; i <= ny; i++) /// 在剩余未匹配的y节点
        if (!visy[i] && d > slack[i])
          d = slack[i];
      for (int i = 1; i <= nx; i++)
        if (visx[i])
          lx[i] -= d;
      for (int i = 1; i <= ny; i++) {
        if (visy[i])
          ly[i] += d;
        else
          slack[i] -= d;
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= ny; i++)
    if (linker[i] != -1)
      res += g[linker[i]][i];
  return res;
}
int main() {
  int n, m, t;
  scanf("%d", &t);
  while (t--) {
    int tmp;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &tmp);
        for (int k = 1; k <= n; k++)
          g[i][(j - 1) * n + k] = -tmp * k;
      }
    nx = n, ny = n * m;
    double sum = -KM();
    printf("%f\n", sum / n);
  }
}
