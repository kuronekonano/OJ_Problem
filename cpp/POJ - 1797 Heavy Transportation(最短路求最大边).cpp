#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int dist[1008];
int ma[1008][1008];
bool vis[1008];
int n, m;
void dijkstra(int s) {
  memset(vis, false, sizeof(vis));
  memset(dist, 0, sizeof(dist));
  for (int i = 1; i <= n; i++)
    dist[i] = ma[s][i];
  dist[s] = 0;
  vis[s] = true;
  for (int i = 2; i <= n; i++) {
    int maxn = 0, maxi = 1;
    for (
        int j = 1; j <= n;
        j++) /// ��¼��Ѱ�ҵĲ������ۼӵ����·��������dist��¼ÿ��·���Ͼ�������С���أ�ÿ�α����ռ���������
    {
      if (!vis[j] && dist[j] > maxn) /// �������ظ���·���Ͽɵ���Ľ�С����
      {
        maxn = dist[j];
        maxi = j;
      }
    }
    vis[maxi] = true;
    for (int j = 1; j <= n; j++)
      if (!vis[j] &&
          dist[j] <
              min(maxn,
                  ma[maxi]
                    [j])) /// ע�����dist����������dist[j]��Сʱ��������һ��maxn��ma�ϵĽϴ�ֵ������
        dist[j] =
            min(maxn,
                ma[maxi][j]); /// û������ж�ֱ�Ӹ�ֵ�ᵼ��dist�����µ�Խ��ԽС
  }
}
int main() {
  int t, x, y, val, cas = 0;
  scanf("%d", &t);
  while (t--) {
    memset(
        ma, 0,
        sizeof(
            ma)); /// ma���޷�����ĵ�Ӧ�ñ����Ϊ0���أ�����Ϊ���ֵ�ᵼ�����ֵ��ֱ��ѡ�ã��޷�������
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &x, &y, &val);
      ma[x][y] = val;
      ma[y][x] = val;
    }
    dijkstra(1);
    printf("Scenario #%d:\n", ++cas);
    printf("%d\n\n", dist[n]); /// ע��������
  }
}
