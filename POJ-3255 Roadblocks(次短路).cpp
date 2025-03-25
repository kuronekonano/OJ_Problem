#include <algorithm>
#include <queue>   ///��������·��࣬��ʵ���������·��������Ĵζ�·
#include <stdio.h> ///�ζ�·
#include <string.h>
#include <vector>
using namespace std;
int dist[5008], dist2[5008]; /// ���·�ʹζ�·�ֱ��������
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
vector<edge> v[5008];
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
      {                     /// �����������´ζ�·
        dist2[tmp.to] = dis;
        q.push(
            edge(tmp.to,
                 dist2[tmp.to])); /// ���ζ�·�Żض����м�������(���ڸ��´ζ�·)
      }
    }
  }
}
int main() {
  int n, r, to, val, from;
  while (scanf("%d%d", &n, &r) != EOF) {
    for (int i = 0; i <= 5000; i++)
      v[i].clear();
    for (int i = 0; i < r; i++) {
      scanf("%d%d%d", &from, &to, &val);
      v[from].push_back(edge(to, val)); /// ����ͼ
      v[to].push_back(edge(from, val));
    }
    dijkstra(1);
    printf("%d\n", dist2[n]);
  }
}
/*
��һ����ϵ�� dist2��i��> dx >dist[i] ��ô���dx�ǿ��Ը���dist2�ģ�
Ȼ�����dx����֮���ַ������ȶ����У���������һ�ο��ܳ��ֵĴζ�
·�ĸ��£�������Ҳ��û�н�����һ��if��ȥ�������·��������Ȼ�п�
�����ڹ�����һ���ζ�·,���Եڶ���pushӦ�����������²������·�Ĵζ�·
*/
