#include <map> ///用map对应出现次数，也就是求和可到达的位置是否存在
#include <stdio.h>
using namespace std;
int main() {
  int n, i, t, temp, sum;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    map<int, int> m;
    int flag = 0;
    sum = 0;
    m[0] = 1; /// 第一个数的总和是0的
    for (i = 0; i < n; i++) {
      scanf("%d", &temp);
      sum += temp;
      m[sum]++;
      flag += m
          [sum -
           47]; /// 出现次数，那个总和出现了几次，就有几个子序列，也就是可以到达的位置
    }
    printf("%d\n", flag);
  }
}
