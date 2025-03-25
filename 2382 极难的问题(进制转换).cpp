#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int num[] = {0, 1, 2, 3, 5, 6, 8, 9};
int ans[20];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int cnt = 0;
    while (n) {
      int tmp = n % 8;
      ans[cnt++] = num[tmp];
      n /= 8;
    }
    for (int i = cnt - 1; i >= 0; i--)
      printf("%d", ans[i]);
    printf("\n");
  }
}
