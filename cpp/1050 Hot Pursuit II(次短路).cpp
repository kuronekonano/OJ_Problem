#include <algorithm>
#include <queue>   ///大体和最短路差不多，其实就是用最短路而计算出的次短路
#include <stdio.h> ///次短路
#include <string.h>
#include <vector>
using namespace std;
int dist[1008], dist2[1008]; /// 最短路和次短路分别用数组存
struct edge {
  int to, val;
  edge(int a = 0, int b = 0) : to(a), val(b) {} /// 结构体构造函数
  bool operator<(const edge &a) const           /// 结构体重载运算符
  {
    if (val == a.val)
      return to > a.to;
    return val >
           a.val; /// 此处虽然是大于号，但是在优先队列中是从小到大排列，队首为最小值
  }
};
vector<edge> v[1008];
void dijkstra(int s) {
  memset(dist, 0x3f, sizeof(dist));
  memset(dist2, 0x3f, sizeof(dist2));
  priority_queue<edge> q;
  q.push(edge(s, 0)); /// 注意起点从1开始而不是从0
  while (!q.empty()) {
    edge top = q.top(); /// 取出最小值
    q.pop();
    for (int i = 0; i < v[top.to].size(); i++) {
      edge tmp = v
          [top.to]
          [i]; /// 和最短路一样，先更新最短路，遍历取出节点所能到达的所有节点，更新所有能到达节点的最短路，这里的新权值，暂时用一个dis做临时存储
      int dis = tmp.val + top.val;
      if (dist[tmp.to] > dis) /// 若新权值比记录的最短路数组要小
      {
        swap(
            dist[tmp.to],
            dis); /// 更新最短路！且，临时存储这个被更换的"前最短路"，用来之后更新次短路，因为这个最短路是仅次于新权值的最短路。
        q.push(edge(tmp.to, dist[tmp.to])); /// 将新最短路塞入队列
      }
      if (dist2[tmp.to] > dis &&
          dis >
              dist[tmp.to]) /// 无论这个dis是否被之前的最短路通过更换来更新过，它都是一个在最短路基础上加上新权值而得到的权值，只要符合小于原次短路且大于最短路的条件
      {
        /// 都能用来更新次短路
        dist2[tmp.to] = dis;
        q.push(edge(tmp.to, dist2[tmp.to])); /// 将次短路放回队列中继续更新
      }
    }
  }
}
int main() {
  int m, n, to, val;
  while (scanf("%d", &m) != EOF) {
    for (int i = 0; i <= 1001; i++)
      v[i].clear();
    for (int i = 1; i <= m; i++) /// m个城市
    {
      scanf("%d", &n);
      for (int j = 1; j <= n; j++) /// 每个城市n条边
      {
        scanf("%d%d", &to, &val);
        v[i].push_back(edge(to, val)); /// 有向图
      }
    }
    dijkstra(1);
    printf("%d\n", dist2[m]);
  }
}
