#include <bits/stdc++.h> ///需要注意的是，只要最后一个询问染色没有出现位置，就一定错误
#define LL                                                                     \
  long long /// 而对于0的处理，当最后询问没有安插位置时，优先安插最后询问使得有解，否则有解情况都被处理成无解了
#define M(a, b)                                                                \
  memset(                                                                      \
      a, b,                                                                    \
      sizeof a) /// 剩余情况，只要保证区间内不存在比自己小的数就行了，那么直接延续上一个或者下一个即可
#define pb(x) push_back(x)
using namespace std;
const int maxn = 2e5 + 7;
int a[maxn], lpos[maxn];
int main() {
  int n, q;
  while (scanf("%d%d", &n, &q) != EOF) {
    int cnt = 0;
    bool flag = true;
    M(lpos, 0);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i])
        lpos[a[i]] = i;
      else
        cnt++;
    }
    for (int i = 2; i <= n; i++)
      if (a[i]) {
        if (a[i] < a[i - 1] && lpos[a[i - 1]] > i) {
          flag = false;
          break;
        }
      } else {
        if (!lpos[q]) {
          a[i] = q;
          lpos[q] = i;
        } else
          a[i] = a[i - 1];
      }
    if (!lpos[q] && cnt == 0)
      flag = false; /// 如果没有安插位置，并且最后询问没有安插，那就GG了
    if (!flag)
      printf("NO\n");
    else {
      printf("YES\n");
      if (cnt == n)
        for (int i = 1; i <= n; i++)
          printf("%d%c", q, i == n ? '\n' : ' ');
      else {
        for (int i = n - 1; i >= 1; i--)
          if (!a[i])
            a[i] = a[i + 1];
        for (int i = 1; i <= n; i++)
          printf("%d%c", a[i], i == n ? '\n' : ' ');
      }
    }
  }
}
