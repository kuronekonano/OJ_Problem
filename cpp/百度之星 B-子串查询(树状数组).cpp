#include <bits/stdc++.h> ///最小字典序子串只可能是单个字母
using namespace std;
const int maxn = 1e5 + 7;
int tre[26][maxn];
void update(int pos, int word) {
  for (int i = pos; i < maxn; i += i & -i)
    tre[word][i]++;
}
int query(int pos, int word) {
  int ans = 0;
  for (int i = pos; i; i -= i & -i)
    ans += tre[word][i];
  return ans;
}
char str[maxn];
int t, n, q;
int main() {
  int cas = 0;
  scanf("%d", &t);
  while (t--) {
    memset(tre, 0, sizeof tre);
    scanf("%d%d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
      update(i, str[i] - 'A');
    int l, r;
    printf("Case #%d:\n", ++cas);
    while (q--) {
      scanf("%d%d", &l, &r);
      for (int i = 0; i < 26; i++) {
        int tmp = query(r, i) - query(l - 1, i);
        if (tmp != 0) {
          printf("%d\n", tmp);
          break;
        }
      }
    }
  }
}
