#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
  int n, x, a[2005];
  while (scanf("%d%d", &n, &x) != EOF) {
    LL sum = 0; /// sum求出若所有数都直接取本身的总花费
    int minn = 0x7fffffff, mini;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
      if (a[i] < minn)
        mini = i, minn = a[i]; /// 找到最小值做遍历起点
    }
    while (true) {
      LL dis = 0;
      for (int i = 0; i < n - 1;
           i++) /// 多次循环，遍历一圈，当前值大于上一个值说明可以通过挪动优化
      {
        if (a[(mini - i + n - 1) % n] > a[(mini - i + n - 2) % n]) {
          dis += a[(mini - i + n - 1) % n] -
                 a[(mini - i + n - 2) % n]; /// 求前后两数差和
          a[(mini - i + n - 1) % n] =
              a[(mini - i + n - 2) %
                n]; /// 将较大数等于前者较小值，说明该数有上一个值挪动而来
        }
      }
      if (dis < x)
        break;
      sum -=
          dis -
          x; /// 因为每次挪动是对整段序列，因此求差值也就是可优化值是对所有两两差值的求和，也就是差值和对比x可优化值，若大于，继续优化
    } /// 用总费用直接减去差值和，从中剃去挪动费用
    printf("%lld\n", sum);
  }
}
/*
后者花费ai前者花费a(i-1)，单独拿来两者花费是ai+a(i-1),
否则是a(i-1)+a(i-1)+x，因为后者比前者大，所以加和必定
大于a(i-1)+a(i-1),那么两者之差就是ai-a(i-1),也就是单独
拿来的花费减去挪动的花费，这个值如果大于x，那么挪动是划
算的，如果小于x说明这里不需要挪动
我不能仅考虑两两之间的差值是否小于x，因为是整体挪动。。
。如果仅是两两差值小于x，求和大于x，必定还可以优化，因为
我明明可以不是单个移动的，而是整体移动的，那么，你更改成
相同值的一些数就可以看做是一段区间，看做一个单独的数，我
其实是在比较当前这个值，和i-1那个区间的所有相等的值、

*/
