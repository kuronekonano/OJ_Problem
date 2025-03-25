#include <stdio.h>
int main() {
  int n, m, i;
  while (scanf("%d%d", &m, &n) != EOF) {
    int ans = 0, flag = 0;
    while (flag < n - 1) {
      ans += m * 2;
      m--;
      flag += 2;
    }
    ans += m;
    printf("%d\n", ans);
  }
}
/// 有m排瓶子，每排n个瓶子，高度从1到m
/// 两个条件，同一行中，相邻的两个瓶子高度差不超过1
/// 同一列中，不能有两个高度相同的瓶子。
/// 问，使每行高度和最小的情况下，最大的高度和是多少
/// 最大高度和：m+m+m-1+m-1...直到加到n个瓶子为止
