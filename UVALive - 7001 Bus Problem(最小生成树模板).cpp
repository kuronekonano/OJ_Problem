#include <stdio.h> ///��С������ģ����
#include <string.h>
#define pppp printf("----------\n");
int ma[1005][1005], dist[1005], m, n;
bool vis[1002];
int prim() {
  memset(vis, false, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  vis[0] = true;
  int minn, mini, sum = 0;
  for (int i = 1; i < n; i++)
    dist[i] = ma[0][i]; /// ���´�0�ڵ㵽��ÿ���ڵ�ľ���
  for (int i = 1; i < n; i++) {
    int minn = 0x7fffffff; /// ÿ�δ�δ��ǽڵ���ѡ����Сֵ���뵽��С��������
    int mini = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && dist[j] < minn) {
        minn = dist[j];
        mini = j;
      }
    }
    sum += minn; /// ��С�������ܳ����
    vis[mini] = true;
    for (int j = 0; j < n; j++)
      if (!vis[j] && ma[mini][j] < dist[j])
        dist[j] = ma[mini][j]; /// �����¼���Ľڵ����ʣ�����нڵ�ĵ������
  }
  return sum;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y, val, total = 0;
    memset(ma, 0x3f, sizeof(ma)); /// ��ͼδ��ͨ����ȫ����ɳ������޴󣬱�ʾ��ͨ
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &x, &y, &val);
      ma[x][y] = val;
      ma[y][x] = val;
      total += val;
    }
    int ans = total - prim();
    printf("%d\n", ans);
  }
}
