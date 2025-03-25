#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e6 + 7;
int tre[maxn], pos[26];
int n, q;
char a[maxn];
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", a + 1);
  M(tre, 0);
  M(pos, 0);
  for (int i = 1; i <= n; i++) {
    tre[i] = tre[pos[a[i] - 'a']] + 1;
    pos[a[i] - 'a'] = i;
  }
  while (q--) {
    scanf("%d", &n);
    printf("%d\n", tre[n]);
  }
}
