#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#define LL long long
using namespace std;
const int maxn = 108;
LL ans;
char aa[maxn];
int n, len;
vector<int> q;
void dfs(int x, char tmp[], bool flag) {
  char a[maxn];
  strcpy(a, tmp);
  if (x == len) {
    if (a[x - 3] == 'A' && a[x - 2] == 'A' && a[x - 1] == 'A')
      return;
    if (x > 2 && a[x - 3] != 'A' && a[x - 2] != 'A' && a[x - 1] != 'A')
      return;
    if (flag) {
      //            printf("------%s\n",a);
      LL sum = 1;
      for (int i = 0; i < q.size(); i++) {
        if (a[q[i]] == 'A')
          sum *= 5ll;
        else if (a[q[i]] == 'B')
          sum *= 20ll;
      }
      ans += sum;
    }
    return;
  }
  if (aa[x] == '_' && x >= 2) {
    q.push_back(x);
    if (a[x - 1] != 'A' || a[x - 2] != 'A') {
      a[x] = 'A';
      dfs(x + 1, a, flag);
    }
    if (a[x - 1] == 'A' || a[x - 2] == 'A') {
      a[x] = 'B';
      dfs(x + 1, a, flag);
      a[x] = 'L';
      flag = true;
      dfs(x + 1, a, flag);
    }
    q.pop_back();
  } else if (aa[x] == '_' && x < 2) {
    q.push_back(x);
    a[x] = 'A';
    dfs(x + 1, a, flag);
    a[x] = 'B';
    dfs(x + 1, a, flag);
    a[x] = 'L';
    flag = true;
    dfs(x + 1, a, flag);
    q.pop_back();
  } else {
    if (a[x - 2] == 'A' && a[x - 1] == 'A' && a[x] == 'A')
      return;
    if (x > 1 && a[x - 2] != 'A' && a[x - 1] != 'A' && a[x] != 'A')
      return;
    if (a[x] == 'L')
      flag = true;
    dfs(x + 1, a, flag);
  }
}
int main() {
  while (scanf("%s", &aa) != EOF) {
    len = strlen(aa);
    ans = 0;
    for (int i = 0; i < len; i++) {
      if (aa[i] == 'A' || aa[i] == 'E' || aa[i] == 'I' || aa[i] == 'O' ||
          aa[i] == 'U')
        aa[i] = 'A';
      else if (aa[i] != '_' && aa[i] != 'L')
        aa[i] = 'B';
    }
    q.clear();
    dfs(0, aa, false);
    printf("%lld\n", ans);
  }
}
