#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int k, n, i, b[1000008];
char a[1000008];
int main() {
  while (scanf("%d", &k) != EOF) {
    scanf("%s", a);
    int n = strlen(a), sum = 0;
    for (i = 0; i < n; i++) {
      sum += a[i] - '0';
      b[i] = a[i] - '0';
    }
    if (sum >= k) {
      printf("0\n");
      continue;
    }
    sort(b, b + n);
    int flag = 0;
    for (i = 0; i < n; i++) {
      sum += 9 - b[i];
      flag++;
      //            printf("=====%d\n",sum);
      if (sum >= k)
        break;
    }
    printf("%d\n", flag);
  }
}
