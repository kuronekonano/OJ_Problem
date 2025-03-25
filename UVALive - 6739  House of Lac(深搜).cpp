#include <stdio.h> ///深搜广搜都行
#include <string.h>
int t, st1, st2, ed1, ed2, n, m;
char ma[502][503];
bool vis[503][502];
int flag[502][502];
int walkx[] = {-1, 0, 1, 0};
int walky[] = {0, -1, 0, 1};
bool ans = false;
void dfs(int ii, int jj) {
  vis[ii][jj] = true;
  for (int i = 0; i < 4; i++) {
    int nexti = ii + walkx[i];
    int nextj = jj + walky[i];
    if (!vis[nexti][nextj] && ma[nexti][nextj] == '.' && nexti >= 1 &&
        nextj >= 1 && nexti <= n && nextj <= m) {
      if (nexti == ed1 && nextj == ed2) {
        ans = true;
        return;
      }
      dfs(nexti, nextj);
    }
    if (ma[nexti][nextj] == '*')
      flag[nexti][nextj]++; /// 接触计数
  }
  for (int i = 0; i < 4; i++) /// 对于消去的*，可以立即从该点搜索下去
  {
    int nexti = ii + walkx[i];
    int nextj = jj + walky[i];
    if (flag[nexti][nextj] >= 2) /// 接触两次后即可消去，并从这开始搜索
    {
      if (nexti == ed1 &&
          nextj == ed2) /// 消去的点若是终点，可以立即得到ans并返回
      {
        ans = true;
        return;
      }
      ma[nexti][nextj] = '.';
      flag[nexti][nextj] = 0;
      dfs(nexti, nextj);
    }
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    ans = false;
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++)
      scanf("%s", ma[i] + 1), getchar();
    memset(vis, false, sizeof(vis));
    memset(flag, 0, sizeof(flag));
    scanf("%d%d%d%d", &st1, &st2, &ed1, &ed2);
    if (st1 == ed1 && st2 == ed2)
      ans = true; /// 起始点等于终点则不用搜索
    if (!ans)
      dfs(st1, st2);
    printf("%s\n", ans ? "YES" : "NO");
  }
}
