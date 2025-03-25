#include <algorithm>
#include <stdio.h> ///���·
#include <string.h>
using namespace std;
int dist[208];
int maps[208][209];
bool vis[208];
int n, m, flag;
void dijkstra(int s, int t, int die) {
  int i, j;
  memset(vis, false, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  flag = dist[1];
  vis[die] = true;
  for (i = 1; i <= n; i++) /// ���е㵽�����ľ���
  {
    dist[i] = maps[s][i];
  }
  dist[s] = 0;             /// �����㳤��Ϊ0
  vis[s] = true;           /// ����߹�
  for (i = 2; i <= n; i++) /// ����n-1��
  {
    int minn = 0x7fffffff, mini;
    for (j = 1; j <= n;
         j++) /// ������Ҫ�������еĵ㣬��Ϊ��һ���ǵ�0������Ϊ���
    {
      if (!vis[j] && dist[j] < minn) {
        minn = dist[j];
        mini = j;
      }
    }
    vis[mini] = true;
    for (j = 1; j <= n; j++) {
      dist[j] = min(dist[j], dist[mini] + maps[mini][j]);
    }
  }
  //    for(i=0;i<n;i++)
  //    {
  //        printf("%d\n",dist[i]);
  //    }
}
int main() {
  int i, j, k, x, y, len[60];
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 0 && m == 0)
      return 0;
    memset(maps, 0x3f, sizeof(maps)); /// ��ʼ����·��Ϊ���޴�(���ɵ���)
    for (i = 0; i < m; i++)           /// m��·
    {
      scanf("%d%d%d", &x, &y, &k);
      if (k < maps[x][y])
        maps[x][y] = maps[y][x] = k; /// һֱ����Ϊ��С·��
    }
    for (i = 2; i <= n - 1; i++) {
      dijkstra(1, n, i);
      len[i] = dist[n];
      //            printf("===%d\n",dist[n]);
    }
    sort(len + 2, len + n);
    if (len[n - 1] == flag) {
      printf("Inf\n");
    } else
      printf("%d\n", len[n - 1]);
  }
  return 0;
}
