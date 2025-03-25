#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 308;
const int mod = 1e9 + 7;
const int inf = 0x7fffffff;
int n;
LL mp[maxn][maxn];
bool flag[maxn][maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%lld", &mp[i][j]);
  bool ans = true;
  LL sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (mp[j][k] > mp[j][i] + mp[i][k])
          ans = false;
        if (mp[j][i] != 0 && mp[i][k] != 0 && j != k &&
            mp[j][k] == mp[j][i] + mp[i][k])
          flag[j][k] = true; /// 中继位置总和标记
      }
    }
  }
  if (!ans) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (!flag[i][j])
        sum += mp[i][j];
  printf("%lld\n", sum);
}
