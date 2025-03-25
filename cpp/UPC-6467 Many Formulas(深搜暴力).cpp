#include <bits/stdc++.h>
#define LL long long
using namespace std;
char str[15];
LL ans;
void dfs(LL sum, int now, int len) {
  if (now == len) {
    //        printf("====%lld\n",sum);
    ans += sum;
    return;
  }
  for (int i = now; i < len; i++) {
    LL tmp = 0;
    for (int j = now; j <= i; j++)
      tmp = tmp * 10 + (str[j] - '0');
    //        printf("now=%d  tmp=%lld   sum=%lld\n",now,tmp,sum);
    dfs(sum + tmp, i + 1, len);
  }
  return;
}
int main() {
  while (scanf("%s", str) != EOF) {
    ans = 0;
    int len = strlen(str);
    dfs(0, 0, len);
    printf("%lld\n", ans);
  }
}
