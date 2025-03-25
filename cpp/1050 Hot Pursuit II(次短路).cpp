#include <algorithm>
#include <queue>   ///��������·��࣬��ʵ���������·��������Ĵζ�·
#include <stdio.h> ///�ζ�·
#include <string.h>
#include <vector>
using namespace std;
int dist[1008], dist2[1008]; /// ���·�ʹζ�·�ֱ��������
struct edge {
  int to, val;
  edge(int a = 0, int b = 0) : to(a), val(b) {} /// �ṹ�幹�캯��
  bool operator<(const edge &a) const           /// �ṹ�����������
  {
    if (val == a.val)
      return to > a.to;
    return val >
           a.val; /// �˴���Ȼ�Ǵ��ںţ����������ȶ������Ǵ�С�������У�����Ϊ��Сֵ
  }
};
vector<edge> v[1008];
void dijkstra(int s) {
  memset(dist, 0x3f, sizeof(dist));
  memset(dist2, 0x3f, sizeof(dist2));
  priority_queue<edge> q;
  q.push(edge(s, 0)); /// ע������1��ʼ�����Ǵ�0
  while (!q.empty()) {
    edge top = q.top(); /// ȡ����Сֵ
    q.pop();
    for (int i = 0; i < v[top.to].size(); i++) {
      edge tmp = v
          [top.to]
          [i]; /// �����·һ�����ȸ������·������ȡ���ڵ����ܵ�������нڵ㣬���������ܵ���ڵ�����·���������Ȩֵ����ʱ��һ��dis����ʱ�洢
      int dis = tmp.val + top.val;
      if (dist[tmp.to] > dis) /// ����Ȩֵ�ȼ�¼�����·����ҪС
      {
        swap(
            dist[tmp.to],
            dis); /// �������·���ң���ʱ�洢�����������"ǰ���·"������֮����´ζ�·����Ϊ������·�ǽ�������Ȩֵ�����·��
        q.push(edge(tmp.to, dist[tmp.to])); /// �������·�������
      }
      if (dist2[tmp.to] > dis &&
          dis >
              dist[tmp.to]) /// �������dis�Ƿ�֮ǰ�����·ͨ�����������¹���������һ�������·�����ϼ�����Ȩֵ���õ���Ȩֵ��ֻҪ����С��ԭ�ζ�·�Ҵ������·������
      {
        /// �����������´ζ�·
        dist2[tmp.to] = dis;
        q.push(edge(tmp.to, dist2[tmp.to])); /// ���ζ�·�Żض����м�������
      }
    }
  }
}
int main() {
  int m, n, to, val;
  while (scanf("%d", &m) != EOF) {
    for (int i = 0; i <= 1001; i++)
      v[i].clear();
    for (int i = 1; i <= m; i++) /// m������
    {
      scanf("%d", &n);
      for (int j = 1; j <= n; j++) /// ÿ������n����
      {
        scanf("%d%d", &to, &val);
        v[i].push_back(edge(to, val)); /// ����ͼ
      }
    }
    dijkstra(1);
    printf("%d\n", dist2[m]);
  }
}
