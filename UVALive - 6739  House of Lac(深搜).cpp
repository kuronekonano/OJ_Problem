#include <stdio.h> ///���ѹ��Ѷ���
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
      flag[nexti][nextj]++; /// �Ӵ�����
  }
  for (int i = 0; i < 4; i++) /// ������ȥ��*�����������Ӹõ�������ȥ
  {
    int nexti = ii + walkx[i];
    int nextj = jj + walky[i];
    if (flag[nexti][nextj] >= 2) /// �Ӵ����κ󼴿���ȥ�������⿪ʼ����
    {
      if (nexti == ed1 &&
          nextj == ed2) /// ��ȥ�ĵ������յ㣬���������õ�ans������
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
      ans = true; /// ��ʼ������յ���������
    if (!ans)
      dfs(st1, st2);
    printf("%s\n", ans ? "YES" : "NO");
  }
}
