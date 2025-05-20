#include <bits/stdc++.h> ///给出1e6+7条边，组成一个矩形，使得其周长面积比最小
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e6 + 7;
int t, n, a[maxn], b[maxn], cnt[10800];
bool vis[10800];
int main() {
  scanf("%d", &t);
  while (t--) {
    M(vis, false);
    M(cnt, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++; /// 记录每条边出现次数
    }
    sort(a, a + n);
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[a[i]] < 2 || vis[a[i]])
        continue; /// 数量不够2条的长度舍去，已经离散化的边舍去
      int sum = cnt[a[i]];
      while (sum >= 2) /// 把边分成2个2个一组，这样能保证正方形也在计算之内
      {
        b[num++] = a[i];
        sum -= 2;
      }
      vis[a[i]] = true;
    }
    double ans = 100000000000;
    int aa, bb;
    for (int i = 0; i < num - 1; i++) {
      double tmp =
          4.0 * (b[i] + b[i + 1]) * (b[i] + b[i + 1]) / (1.0 * b[i + 1] * b[i]);
      if (tmp < ans) {
        ans = tmp;
        aa = b[i], bb = b[i + 1];
      }
    }
    printf("%d %d %d %d\n", aa, aa, bb, bb);
  }
}
