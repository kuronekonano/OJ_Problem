#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int inf = 0x7fffffff;
struct edge /// ��ʽǰ���ǽ�ͼ
{
  int to, val, rev; /// rev����ȡ����
  edge() {}
  edge(int a, int b, int c) {
    to = a;
    val = b;
    rev = c;
  }
};
vector<edge> mp[maxn];
void add(int from, int to, int val) /// �ӱ�
{
  mp[from].push_back(edge(to, val, mp[to].size())); /// ���ߣ�revΪto�����±�
  mp[to].push_back(
      edge(from, 0, mp[from].size() - 1)); /// ���ߣ������ߵ�revΪ���ߵı��
}
int t, n, m;
int dep
    [20]; /// depΪdinic�㷨�еķֲ�ͼ����ȣ�����Ϊ�ӿ�ʼ����ýڵ���̾���,�����СΪ�������٣�����ֻ��15
int bfs() {
  memset(dep, -1, sizeof dep);
  queue<int> q;
  while (!q.empty())
    q.pop();
  dep[1] = 0;
  q.push(1);
  while (!q.empty()) /// ���ѷֲ�
  {
    int tmp = q.front();
    q.pop();
    if (tmp == n)
      return 1; /// �����ѻ����ߵ����˵�����Լ�������
    for (int i = 0; i < mp[tmp].size(); i++) {
      int &to = mp[tmp][i].to, flow = mp[tmp][i].val;
      if (dep[to] == -1 &&
          flow) /// ���õ㻹û�б��ֲ㣬û���ߵ��ı�ǣ�������������ô����ȥ
      {
        dep[to] = dep[tmp] + 1;
        q.push(to);
      }
    }
  }
  return 0;
}
int dfs(int s, int t, int flow) /// ��Ή���
{
  if (s == t)
    return flow; /// ��������
  int pre = 0;
  for (int i = 0; i < mp[s].size(); i++) {
    int &to = mp[s][i].to, val = mp[s][i].val;
    if (dep[s] + 1 == dep[to] &&
        val > 0) /// ��һ�Ή���Ľڵ����Ӧ�ڸõ������+1
    {
      int tmp = min(flow - pre, val);  /// ������ʣ������ȡ��Сֵ
      int sub = dfs(to, t, tmp);       /// ����ͨ��bfs���������ҹ�������
      mp[s][i].val -= sub;             /// �����-
      mp[to][mp[s][i].rev].val += sub; /// �����+
      pre += sub;
      if (pre == flow)
        return pre; /// ��Ή���������
    }
  }
  return pre;
} /// �ֲ��ÿ�Ή��������
int dinic() {
  int ans = 0;
  while (bfs())
    ans += dfs(1, n, inf);
  return ans;
}
int main() {
  int cas = 1;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i <= n; i++)
      mp[i].clear();
    int from, to, val;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &from, &to, &val);
      add(from, to, val);
    }
    printf("Case %d: %d\n", cas++, dinic());
  }
}
