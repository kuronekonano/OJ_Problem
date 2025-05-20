#include <math.h>
#include <stdio.h>
int main() {
  int t, a1, b1, a2, b2, v, st, c1,
      c2; // 有几个题目的隐藏变量，原来草的数量，草的生长速度，都要自己求
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d", &a1, &b1, &a2, &b2, &c1);
    v = fabs((a1 * b1) - (a2 * b2)) /
        fabs(b1 -
             b2); // 利用两次羊数量和天数所算出的总数的差值，来求出草生长的速度
    st = (a1 * b1) - (b1 * v); // 将求出的生长速度带入原式以求出原来草的总数
    c2 = st / (c1 - v);        // 带入c1以求出c2的值
    printf("%d\n", c2);
  }
}
