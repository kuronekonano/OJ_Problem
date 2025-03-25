#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
int n;
char a[maxn];
int main() {
  while (scanf("%s", a) != EOF) {
    int ans = 0;
    int len = strlen(a);
    for (int i = 1; i < len - 1; i++)
      if (a[i - 1] != a[i + 1])
        ans++;
    if (ans == 0) {
      printf("Second\n");
      continue;
    }
    if (a[0] != a[len - 1])
      printf("%s\n", len % 2 ? "First" : "Second");
    else
      printf("%s\n", len % 2 ? "Second" : "First");
  }
}
