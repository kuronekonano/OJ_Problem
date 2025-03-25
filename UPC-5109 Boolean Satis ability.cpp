#include <bits/stdc++.h>
#define LL long long
using namespace std;
char str[1009];
LL poww(LL a, LL b) {
  LL ans = 1;
  while (b) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
int main() {
  bool vis[304], vis2[304];
  while (scanf("%s", str) != EOF) {
    bool flag = false;
    memset(vis, false, sizeof(vis));
    memset(vis2, false, sizeof(vis2));
    LL num = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
      if (str[i] == '~') {
        if (vis[str[i + 1]] == true)
          flag = true;
        else
          vis2[str[i + 1]] = true, num++;
        i++;
        continue;
      }
      if ((str[i] >= 'A' && str[i] <= 'Z') ||
          (str[i] >= 'a' && str[i] <= 'z')) {
        if (vis[str[i]]) {
          if (vis2[str[i]] == true)
            flag = true;
        } else {
          num++;
          vis[str[i]] = true;
        }
      }
    }
    LL ans = poww((LL)2, num);
    printf("%lld\n", flag ? ans : ans - 1);
  }
}
