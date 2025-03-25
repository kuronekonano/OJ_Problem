#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
double ma[208][208];
double dist[208];
bool vis[208];
int n, cas = 0;
void dijkstra() {
  for (int i = 0; i <= 200; i++)
    dist[i] = 1e10;
  memset(vis, false, sizeof(vis)); /// �������·��ʹѡ���·�����ǽ�С��
  for (int i = 1; i < n; i++)
    dist[i] = ma[0][i];
  dist[0] = 0;
  vis[0] = true;
  for (int i = 1; i < n; i++) {
    double minn = 1e10;
    int mini;
    for (int j = 0; j < n;
         j++) /// ÿ�α��(���ߵ�)·�ζ����ҵ��������µ�����̵�
    {
      if (!vis[j] && dist[j] < minn) {
        minn = dist[j];
        mini = j;
      }
    }
    vis[mini] = true; /// �ҵ������·�κ󣬸���Ѱ�ҵ���ʣ�����̾���
    for (
        int j = 0; j < n;
        j++) /// ע�⣬����dist��¼���ǵ���ĳ��������·�����·�εĴ�С������ÿ�������������뽫����¼���̳���ȥ��������������������һ�����·��
    {
      /// ��ô������·��ֵҲ����Ϊ��һ��������·��ֵ����Ϊ������һ���㾭���˵�ǰ����·
      dist[j] = min(
          dist[j],
          max(dist[mini],
              ma[mini]
                [j])); /// ��dist[j]�����Լ������·��ѡ��Ƚ�С�ģ����������룬��Ȼ�Ѿ�������dist����ô��ξ��������С�ģ���������ϴ�ĵ㲻��Ӱ���0�㵽��1��ĳ���
    } /// ʣ��������ѡֵ������һ����������룬�Լ�����һ���㵽���Լ���������ĸ��£������һ���㵽���Լ��ľ��������ô��������벻��֮ǰ�̳У��������¡�������������ر��ʱ������Ӱ����ǰ�����j�����С���룬Ҳ���ǲ�����Զ·
    //        for(int i=0;i<n;i++)printf("%d ----->%f\n",i,dist[i]);
    //        printf("======\n");
  }
}
int main() /// ��ĿҪ�󣬴ӵ�0��������������1������·���е����ֵ����0��1�ĳ��Ȳ���Ҫ�󣬵���0��1������·�ε����ֵ��δ�ߵ�·�ζ�С
{
  while (scanf("%d", &n) != EOF) {
    if (!n)
      return 0;
    memset(ma, 0, sizeof(ma));
    int x[208], y[208];
    for (int i = 0; i < n; i++)
      scanf("%d%d", &x[i], &y[i]);
    for (int i = n - 1; i >= 0; i--)
      for (int j = i - 1; j >= 0; j--)
        ma[i][j] = ma[j][i] =
            sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    dijkstra();
    printf("Scenario #%d\n", ++cas);
    printf("Frog Distance = %.3f\n\n", dist[1]);
  }
}
