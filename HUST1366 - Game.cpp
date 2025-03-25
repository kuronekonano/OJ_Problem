#include <algorithm>
#include <stdio.h>
using namespace std;
unsigned long long a[100];
bool judge(unsigned long long k) {
  for (int i = 1; i <= 92; i++) {
    if (k == a[i]) {
      return true;
    }
  }
  return false;
}
int main() {
  unsigned long long i, j, n;
  a[1] = 1, a[2] = 2;
  for (i = 3; i <= 92; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  //    for(i=1;i<=92;i++)
  //    {
  //        printf("%llu\n",a[i]);
  //    }
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%llu", &n);
    if (n == 1) {
      printf("Alice Lose\n");
      continue;
    }
    bool flag = false;
    int mark;
    for (i = 92; i >= 1; i--) {
      if (a[i] < n) {
        flag = true;
        n = n - a[i];
      }
      if (a[i] == n) {
        break;
      }
    }
    if (!flag) {
      printf("Alice Lose\n");
    } else {
      printf("Alice Win, take %llu coins first\n", n);
    }
  }
}
