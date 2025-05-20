#include <stdio.h>
long long a[100009];

void inti() {
  a[1] = 2;
  for (long long i = 2; i <= 100000;
       i++) /// 这里i是用来相乘的，因此可能会爆，要用long long
  {
    a[i] = i * (i + 1) * (i + 1) - i + 1;
  }
}
int main() {
  inti();
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) /// 这里仅仅是输出，所以不会爆
    {
      printf("%lld\n", a[i]);
    }
  }
  return 0;
}
