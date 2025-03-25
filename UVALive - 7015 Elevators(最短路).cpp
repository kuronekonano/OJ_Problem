#include <queue>
#include <stdio.h> ///¥��֮��û��¥�ݣ�ֻͨ���������ߣ����������������֮�䶼����¥������������еĵ��ݣ�����ʱ�����¥��֮���Ȩֵ����һ�����·����
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 208;
const int MAX = 0x7fffffff;
int dist[N];
int n, flag;
struct Edge {
  int to, val;
  Edge(int a = 0, int b = 0) : to(a), val(b) {}
  bool operator<(const Edge &a) const {
    if (val == a.val)
      return to < a.to;
    return val > a.val;
  }
};
vector<Edge> v[N];
void dijkstra(int s) {
  memset(dist, 0x3f, sizeof(dist));
  flag = dist[0];
  dist[s] = 0;
  priority_queue<Edge> q;
  q.push(Edge(s, 0));
  while (!q.empty()) {
    Edge top = q.top();
    q.pop();
    for (int i = 0; i < v[top.to].size(); i++) {
      Edge tmp = v[top.to][i];
      if (dist[tmp.to] > top.val + tmp.val) {
        dist[tmp.to] = top.val + tmp.val;
        q.push(Edge(tmp.to, dist[tmp.to]));
      }
    }
  }
}
int main() {
  int i, j, k, x, y, num;
  int s, t;
  while (scanf("%d%d%d", &num, &s, &t) != EOF) {
    if (!num && !s && !t)
      return 0;
    n = 0;
    for (int i = 0; i <= N; i++)
      v[i].clear(); ///\���ͼ
    for (int i = 0; i < num; i++) {
      int floor,
          exc[160]; /// n��Ϊ��¥������ֻ�������е��ݿɵ������߲������ж�
      scanf("%d", &floor);            /// ��i������
      for (int j = 0; j < floor; j++) /// ÿ�����ݿ��Ե����¥��
      {
        scanf("%d", &exc[j]);
        if (exc[j] > n)
          n = exc[j];
        for (int vv = 0; vv < j;
             vv++) /// ����ͼ��ÿ����һ����¥�������֮ǰ����¥��
        {
          v[exc[j]].push_back(Edge(exc[vv], abs(exc[vv] - exc[j])));
          v[exc[vv]].push_back(Edge(exc[j], abs(exc[vv] - exc[j])));
        }
      }
    }
    dijkstra(s);
    printf("%d\n", dist[t]);
  }
}
