#include <algorithm>
#include <queue>
#include <stdio.h> ///�����EK�㷨 O(n*m^2)
#include <string.h>
#define LL long long
using namespace std;
const int maxn = 208;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn], fa[maxn], flow[maxn];
int n, m;
queue<int> q;
int bfs(int s, int t) /// ����������·
{
  while (!q.empty())
    q.pop();
  memset(fa, -1, sizeof fa);
  fa[s] = 0, flow[s] = inf;
  q.push(s);
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (tmp == t)
      break;
    for (int i = 1; i <= n; i++) {
      if (i != s && mp[tmp][i] > 0 && fa[i] == -1) {
        fa[i] = tmp;
        flow[i] =
            min(flow[tmp],
                mp[tmp][i]); /// ÿ���ߵ������������������ϵ�������������С��
        q.push(i);
      }
    }
  }
  if (fa[t] == -1)
    return -1;
  return flow[t];
}
int EK(int s, int t) /// ÿ��ֻ����һ����
{
  int add = 0, sum = 0;
  while (true) {
    add = bfs(s, t);
    if (add == -1)
      break;
    int tmp = t;
    while (tmp != s) /// ����·����¼��·�����ӷ��߲���С����
    {
      mp[fa[tmp]][tmp] -= add;
      mp[tmp][fa[tmp]] += add;
      tmp = fa[tmp];
    }
    sum += add; /// ÿ���һ������·��������������
  }
  return sum;
}
int main() {
  while (scanf("%d%d", &m, &n) != EOF) {
    int from, to, val;
    memset(flow, -1, sizeof flow);
    memset(mp, 0, sizeof mp);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &from, &to, &val);
      mp[from][to] += val; /// �ڽӾ���ͼ
    }
    printf("%d\n", EK(1, n));
  }
}
