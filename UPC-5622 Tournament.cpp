#include <bits/stdc++.h>
using namespace std;
vector<int> son[100005];
int n, tmp;
int dfs(int i) {
  if (son[i].size() == 0)
    return 0;
  vector<int> pri;
  for (int j = 0; j < son[i].size();
       j++) /// 得到该节点所有的子节点，对于每个子节点，深度都是自己的子树
    pri.push_back(dfs(son[i][j]));
  int maxn = 1;
  sort(pri.begin(), pri.end());
  for (int j = 0; j < pri.size();
       j++) /// 子节点中深度找出深度最深的，作为总深度返回
  {
    if (pri[j] + pri.size() - j > maxn)
      maxn =
          pri[j] - j +
          pri.size(); /// size表示该层要赢得比赛所要走的最小深度，在此基础上均摊使得深度最小，然后返回值为最大深度，最大深度为当前结点的最小深度加上均摊后的子树最大深度
  } /// 位序j表示从小到大的深度，说明这些结点在何时与i结点对战使总深度会最小，尽量均摊，使子树高深度的上移，也就是使得j较小的时候接上较大的深度子树
  return maxn;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= n; i++)
      son[i].clear();
    for (int i = 2; i <= n; i++) {
      scanf("%d", &tmp);
      son[tmp].push_back(i);
    }
    printf("%d\n", dfs(1));
  }
}
