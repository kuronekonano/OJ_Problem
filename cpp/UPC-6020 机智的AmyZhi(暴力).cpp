#include <stdio.h> ///问输入一个n，求一个最小的m使得m加上m的每一数位上的值结果等于n
#define LL                                                                     \
  long long /// 因为最多加上的值不会超过当前位数*9，因此只用遍历这段距离即可
int main() {
  int t;
  LL n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    LL tmp = n;
    int len = 0;
    while (tmp) {
      tmp /= 10;
      len++;
    }
    int sub = len * 9;
    bool flag = false;
    for (LL i = n - sub; i < n; i++) {
      tmp = i;
      LL sum = 0;
      while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
      }
      //            printf("%lld -----> %lld\n",i,sum+i);
      if (sum + i == n) {
        printf("%lld\n", i);
        flag = true;
        break;
      }
    }
    if (!flag)
      printf("Stupid SiriusRen\n");
  }
}
