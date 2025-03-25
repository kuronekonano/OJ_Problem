#include <algorithm>
#include <queue>
#include <stdio.h> ///�Խ������������յ��ŵ�Ȩ�����Ȩ���·
#include <string.h>
#include <vector>
using namespace std;
struct edge {
  int to, val;
  edge(int a = 0, int b = 0) : to(a), val(b) {}
  bool operator<(const edge &a) const { return val > a.val; }
};
vector<edge> v[100008];
int dist[100008];
void dijkstra() /// ���·
{
  memset(dist, 0x3f, sizeof(dist));
  priority_queue<edge> q;
  q.push(edge(0, 0));
  dist[0] = 0;
  while (!q.empty()) {
    edge top = q.top();
    q.pop();
    for (int i = 0; i < v[top.to].size(); i++) {
      edge tmp = v[top.to][i];
      if (dist[tmp.to] > tmp.val + top.val) {
        dist[tmp.to] = tmp.val + top.val;
        q.push(edge(tmp.to, dist[tmp.to]));
      }
    }
  }
}
int main() {
  int t, n, city;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; i++)
      v[i].clear(); /// һ��Ҫ���������������ᳬʱ���γ�һ����β�������ƴ�ɵĳ���ͼ
    for (int i = 1; i <= n; i++) {
      scanf("%d", &city); /// ������е�Ȩ
      v[0].push_back(edge(
          i,
          city)); /// �����������Ϊ0�ŵ㣬�����е��ȡֵ���ӵ���ʼ�ڵ㣬����ʼ�ڵ�ѡ��Ӧ�ô��ĸ���������(����)
      v[i].push_back(edge(
          n + 1,
          -city)); /// �����յ���Ϊn+1�ŵ㣬�յ�Ͷ�����е��ܵ���ĵ��У�ʹ���·�п�����ÿ���㶼��ѡ�񵽴��յ㣡
    }
    int from, too, vv;
    for (int i = 1; i <= n - 1; i++) {
      scanf("%d%d%d", &from, &too, &vv);
      v[from].push_back(edge(too, vv));
      v[too].push_back(edge(from, vv));
    }
    dijkstra();
    printf("%d\n", -dist[n + 1]);
  }
  return 0;
}
/// ��������������յ㣬�൱�ڣ����������·��֮����Сʱ׬��Ǯ���
/// ��ˣ��������裬�۵�ǮΪ����������ǮΪ���������·����������ʹ�����٣�������������һ����С�ĸ�ֵ��ʹ������С��ȥ�ܴ��ֵ�������һ����С�ĸ���������������෴���������Ǯ��
/// ע�⣬ֻ����ʼ��(�����)���յ�(�����)��Ҫ�����Ȩ���������ȫ�������Ȩ����ˣ������е�ĵ�Ȩ��ȡ��ֵ(��Ϊ����Ļ���)�����һ����Ȩ����������ʼ�ڵ�
/// ���е�ĵ�Ȩ��ȡ��ֵ(���������)�����һ������Ȩ���������յ㣬������������㵽�������յ�Ĺ��̼��Ǵ����е����ҵ����ʵ�Ȩ����С��Ȩ����ȥ����Ȩ�����·����
/// ����һ��ʼѡ������ʼ��Ȩ��������ɱ���С���Ǹ����У������Ⲣ����������Ǹ��������飬�������·�㷨����������Ϊѡȡ�����̱��ɳ����·��һ���������Ǹ���С��ʼ���dist�Իᱻ���µ���
/// �Ӷ���Ϊ������ʼ��ľ����㡣���գ������е�Ȩ�кͱ�Ȩ�У�ȡ����С��Ȩֵ֮�͵����յ�(���뾭��һ������Ȩ��������ĳ��������)��ʵ����С�����������
