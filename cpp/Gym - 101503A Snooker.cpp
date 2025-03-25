#include <algorithm>
#include <iostream>
#include <stdio.h> ///Ë¹Åµ¿ËÄ£Äâ
#include <string>
using namespace std;
int main() {
  int n;
  int a[10];
  char last[10];
  while (scanf("%d", &a[1]) != EOF) {
    int sum = 0, maxn = 0;
    for (int i = 2; i < 8; i++) {
      scanf("%d", &a[i]);
      if (a[i])
        sum += i;
      if (a[i])
        maxn = i;
    }
    scanf("%s", last);
    int ans = 0;
    if (last[0] == 'C' || last[0] == 'N') {
      ans += a[1] * (maxn + 1);
      ans += sum;
    } else if (last[0] == 'R') {
      ans += a[1] * (maxn + 1);
      ans += maxn + sum;
    }
    printf("%d\n", ans);
  }
}
