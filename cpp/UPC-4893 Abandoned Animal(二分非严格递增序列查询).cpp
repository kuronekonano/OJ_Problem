#include <bits/stdc++.h> ///对买的商品位置进行排序后分类，按照非严格递增的顺序二分查找每个商品的位置，能找到这样序列再逆向回去查询
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int n, k, m;
vector<int> pos[maxn];
map<string, int> mp;
string a, b[maxn];
int vis[maxn];
int main() {
  int tmp, cnt = 0;
  scanf("%d%d", &n, &k);
  mp.clear();
  for (int i = 0; i < k; i++) {
    scanf("%d", &tmp);
    cin >> a;
    if (mp[a] == 0)
      mp[a] = ++cnt;
    pos[mp[a]].pb(tmp);
  }
  for (int i = 1; i <= cnt; i++)
    sort(pos[i].begin(), pos[i].end());
  scanf("%d", &m);
  bool flag = true;
  int num = 0, tp;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    tmp = mp[b[i]];
    if (i == 1)
      tp = pos[tmp][0], vis[i] = tp;
    if (i != 1 && flag) {
      num =
          lower_bound(pos[tmp].begin(), pos[tmp].end(), tp) - pos[tmp].begin();
      if (num == pos[tmp].size())
        flag = false;
      else
        tp = pos[tmp][num], vis[i] = tp;
    }
  }
  if (!flag) {
    printf("impossible\n");
    return 0;
  }
  if (flag && num != pos[mp[b[m]]].size() - 1) {
    printf("ambiguous\n");
    flag = false;
    return 0;
  }
  for (int i = m - 1; i >= 1; i--) {
    tmp = mp[b[i]];
    num = lower_bound(pos[tmp].begin(), pos[tmp].end(), tp) - pos[tmp].begin();
    if (num == pos[tmp].size())
      num--;
    if (tp < pos[tmp][num])
      num--;
    tp = pos[tmp][num];
    if (tp != vis[i]) {
      printf("ambiguous\n");
      flag = false;
      break;
    }
  }
  if (flag)
    printf("unique\n");
}
/*
6
6
0 B
1 C
2 A
3 A
4 B
5 C
3
A
B
C

3
3
0 A
1 A
2 A
1
A

3
3
0 A
1 B
2 B
1
A


3
3
0 chocolate
1 icecream
2 cookies
3
chocolate
cookies
icecream

4
5
0 A
1 A
1 B
2 B
3 C
3
B
A
C


5
7
0 C
2 A
4 A
1 B
4 B
2 C
4 C
3
A
B
C

6
8
1 A
4 A
5 A
3 B
4 B
0 C
2 C
3 C
3
A
B
C
*/
