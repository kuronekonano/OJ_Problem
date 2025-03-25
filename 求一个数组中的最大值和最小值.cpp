#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
  int n, a[39];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    printf("max=%d,min=%d\n", a[n - 1], a[0]);
  }
  return 0;
}
