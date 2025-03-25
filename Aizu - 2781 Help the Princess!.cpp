#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
struct point {
  int x, y;
};
int vis[208][208]; /// 作为标记和记录步数
int walkx[5] = {0, 0, 1, -1};
int walky[5] = {1, -1, 0, 0};
char a[208][210];
int main() /// 从出口向外广搜即可，找到公主和士兵，比较最短距离，若小于到达士兵的距离则可以逃出去
{
  int i, j, n, m;
  while (
      scanf("%d%d", &n, &m) !=
      EOF) /// 注意分两种情况，若两人都搜到则比较距离，若搜不到公主则被墙封死，输出No，若只搜到公主则一定是Yes
  {
    point out;
    memset(a, 0, sizeof(a));
    for (i = 0; i < n; i++) {
      scanf("%s", a[i]);
      for (j = 0; j < m; j++)
        if (a[i][j] == '%') /// 标记出口
        {
          out.x = i;
          out.y = j;
        }
    }
    point pri, sol;
    bool flag1 = false, flag2 = false;
    memset(vis, 0, sizeof(vis));
    queue<point> q;
    while (!q.empty())
      q.pop();
    q.push(out);           /// 从出口向外搜
    vis[out.x][out.y] = 1; /// 标记出口
    while (!q.empty()) {
      point tmp;
      tmp = q.front();
      q.pop();
      for (i = 0; i < 4; i++) {
        int xx = tmp.x + walkx[i];
        int yy = tmp.y + walky[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' &&
            !vis[xx][yy]) {
          vis[xx][yy] = vis[tmp.x][tmp.y] + 1;
          point next;
          next.x = xx;
          next.y = yy;
          q.push(next);
          if (a[next.x][next.y] == '@') {
            pri.x = next.x;
            pri.y = next.y;
            flag1 = true;
          }
          if (a[next.x][next.y] == '$' && !flag2) {
            sol.x = next.x;
            sol.y = next.y;
            flag2 = true;
          }
          if (flag1 && flag2)
            break;
          if (vis[xx][yy] > n * m)
            break;
        }
      }
    }
    if (flag2 && flag1) {
      if ((vis[sol.x][sol.y] - 1) <= (vis[pri.x][pri.y] - 1)) {
        printf("No\n");
      } else {
        printf("Yes\n");
      }
    } else if (flag1 && !flag2)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
