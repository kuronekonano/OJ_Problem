#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, i;
  int a[100005];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
  return 0;
}
