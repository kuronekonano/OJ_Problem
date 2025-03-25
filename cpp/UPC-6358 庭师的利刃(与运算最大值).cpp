#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e6 + 10;
const int inf = 0x7fffffff;
const int mod = 1e9 + 7;
int n;
int num[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &num[i]);
    for (int i = 31; i >= 1; i--) {
      int cnt = 0;
      for (int j = 1; j <= n; j++)
        if (((ans & num[j]) == ans) && (num[j] & (1 << (i - 1))))
          cnt++;
      if (cnt > 1)
        ans += (1 << (i - 1));
    }
    printf("%d\n", ans);
  }
}
/*
5
12 5 6 3 1
3
32 85 170
2
1 9
2
20 36
5
8 16 33 72 86
2
0 1
3
511 68 96
*/
