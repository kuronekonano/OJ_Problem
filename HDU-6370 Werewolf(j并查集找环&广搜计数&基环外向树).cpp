#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
struct edge {
  int to;
  bool flag;
  edge() {}
  edge(int a, bool b) {
    to = a;
    flag = b;
  }
};
queue<int> q;
vector<edge> mp[maxn];
int t, n;
int r[maxn];
bool vis[maxn];
int finds(int x) { return r[x] == x ? x : r[x] = finds(r[x]); }
void join(int x, int y) {
  int a = finds(x), b = finds(y);
  if (a != b)
    r[b] = a; /// ��������Ĵ��룬���鼯д����
}
void init() {
  for (int i = 0; i <= n; i++)
    mp[i].clear(), r[i] = i;
  M(vis, false);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    init();
    int son;
    char str[13];
    for (int i = 1; i <= n;
         i++) /// ��ָ�Ϲ�ϵ�����߽�������ߣ��ɱ�ָ�ϵ��� ָ�� ָ�ϵ���
              /// ��ʾ�����ָ�ϵ��˳������ˣ���ô���ƣ�ָ����ʵ����ı�Ȼ����
    {
      scanf("%d%s", &son, str);
      mp[son].pb(edge(i, str[0] == 'w' ? true : false));
      if (str[0] != 'w')
        join(i, son); /// ����ָ��Ϊ�����һȺ�˲��鼯��ͨ�ɻ�
    }
    while (!q.empty())
      q.pop();
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < mp[i].size();
           j++) /// ��������Ĵ��룬forѭ��д����i++
      {
        if (finds(mp[i][j].to) == finds(i) && mp[i][j].flag &&
            !vis[i]) /// �������ߣ����ó���Ϊ�ǵ�ָ��ʱ����˫����һ�������У�˵������ì��
        {
          ans++; /// ����ì�ܵ��˾��Ǳ�ָ��Ϊ�ǵ��ˣ���ôָ����Ϊ������������ȫ���Ǵ���
          q.push(i);
          vis[i] = true;
        }
      }
    while (
        !q.empty()) /// ���Ѿ�ȷ���ģ��������е��ǽ��й��ѣ�������������п��ܳ��ֵ���
    {
      int top = q.front();
      q.pop();
      for (int i = 0; i < mp[top].size(); i++) {
        if (mp[top][i].flag || vis[mp[top][i].to])
          continue;
        ans++;
        q.push(mp[top][i].to);
      }
    }
    printf("0 %d\n", ans);
  }
}
/*
999
2
2 werewolf
1 werewolf
3
2 v
1 v
2 w
*/
