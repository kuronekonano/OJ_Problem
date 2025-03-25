#include <stdio.h> ///����ͼ���ƥ��
#include <string.h>
struct man {
  int st, ed;
} men[202], work[202];
int match[505];
bool edge[505][505], vis[505];
int n, k, t;
bool KM(int x) {
  for (int i = 1; i <= n; i++) /// ��������
  {
    if (!vis[i] && edge[x][i]) /// �������x�ܱ�����i�����ҹ���iû������
    {
      vis[i] = true; /// �ù�����i
      if (match[i] == 0 || KM(match[i])) {
        match[i] = x; /// ������Թ�ϵ
        return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(edge, false, sizeof(edge));
    memset(match, 0, sizeof(match));
    int x, y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d:%d", &x, &y);
      men[i].st = x * 60 + y;
      scanf("%d:%d", &x, &y);
      men[i].ed = x * 60 + y;
    }
    for (int i = 1; i <= k; i++) {
      scanf("%d:%d", &x, &y);
      work[i].st = x * 60 + y;
      scanf("%d:%d", &x, &y);
      work[i].ed = x * 60 + y;
      for (int j = 1; j <= n; j++)
        if (work[i].st >= men[j].st && men[j].ed >= work[i].ed)
          edge[i][j] = true; /// ע�⹤��ʱ�䱻�����ڹ���ʱ�������ڣ���
    }
    int sum = 0;
    for (int i = 1; i <= k; i++) {
      memset(vis, false, sizeof(vis));
      if (KM(i))
        sum++;
    }
    printf("%d\n", sum);
  }
}
