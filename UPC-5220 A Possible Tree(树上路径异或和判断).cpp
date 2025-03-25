#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int n, t, q;
struct edge {
  int to;
  LL val;
  edge() {}
  edge(int a, LL b) {
    to = a;
    val = b;
  }
};
vector<edge> mp[maxn];
int z[maxn];
LL sum[maxn];
bool vis[maxn];
int finds(int x) { return z[x] == x ? x : z[x] = finds(z[x]); }
void dfs(int rt, int fa) {
  if (vis[rt])
    return;
  vis[rt] = true;
  for (int i = 0; i < mp[rt].size(); i++) {
    edge tmp = mp[rt][i];
    if (tmp.to == fa)
      continue;
    sum[tmp.to] = sum[rt] ^ tmp.val; /// ���·����
    dfs(tmp.to, rt);
  }
  return;
}
int from[maxn], to[maxn];
LL val[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= n; i++)
      mp[i].clear(), z[i] = i, vis[i] = false, sum[i] = 0; /// ��ʼ��
    for (int i = 0; i < n - 1; i++)
      scanf("%*d%*d");
    for (
        int i = 1; i <= q;
        i++) { /// ������Ч���Ǹ���·�����͵���Ϣ����ô���Ͱ����п��ܵ�·�����Ͷ���Ϊ����ȷ��
      scanf(
          "%d%d%lld", &from[i], &to[i],
          &val[i]); /// ��q����ȷ����ȷ�������·��������ʵ�����������ͼû�и�����Ȩ����û��ʲô��
      int fx = finds(from[i]),
          fy = finds(to[i]); /// ���鼯�ж��Ƿ��л����л�������
      if (fx !=
          fy) /// ������q������·����������Ϊ�϶���ͨ����ֻ��Ψһ·������ô������ʵ��������Ч�ģ�ֻ�ǲ�ȷ��������ȷ���
      {
        z[fy] = fx;
        mp[from[i]].pb(edge(to[i], val[i]));
        mp[to[i]].pb(edge(from[i], val[i]));
      } /// �����Ҫ�����ȷ��·�����͵��������Ǿͽ�ǰ����Ĭ���ǶԵģ��ڴ˻����Ͻ�ͼȥ�жϺ���������������˳���ж���ȥһ������������
    }
    for (
        int i = 1; i <= q;
        i++) /// ��Ϊq�����ܸ������Ĳ�����һ�����������������Ƕ�ã�����Ҫ����ǵ�����ÿ�����㵽���·����
      if (!vis[from[i]])
        dfs(from[i], 0);
    int ans = 0;
    for (
        int i = 1; i <= q;
        i++) /// ���õ����н�����ǰ�����������͵������ж���������ж��������м���
      if ((sum[from[i]] ^ sum[to[i]]) != val[i])
        break;
      else
        ans++;
    printf("%d\n", ans);
  }
}
