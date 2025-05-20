#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int n;
int a[201000];        /// 原数列存储
int dmin[201000][51]; /// 最小值
int dmax[201000][51]; /// 最大值
void rmq_init() {
  for (int i = 1; i <= n; i++)
    dmin[i][0] = a[i], dmax[i][0] = a[i]; /// 初始化，其实是2^0，因此是本身
  for (int j = 1; (1 << j) < n; j++)      /// 状态转移,2的j次方的长度
  {
    for (int i = 0; i + (1 << j) - 1 <= n; i++) /// 起始位置
    {
      dmin[i][j] = min(
          dmin[i][j - 1],
          dmin[i + (1 << (j - 1))]
              [j -
               1]); /// 在当前长度下，覆盖了上一个长度的两个区间，由这两个区间取一个最值继承
      dmax[i][j] = max(dmax[i][j - 1], dmax[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int rmq_min(int l, int r) {
  int k = log2(r - l + 1);
  return min(dmin[l][k], dmin[r - (1 << k) + 1][k]);
}

int rmq_max(int l, int r) {
  int k = log2(r - l + 1);
  return max(dmax[l][k], dmax[r - (1 << k) + 1][k]);
}
int main() {
  int q, i;
  while (scanf("%d%d", &n, &q) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int x, y;
    rmq_init(); /// 处理
    //        for(i=0;i<=n;i++)
    //        {
    //            for(int j=0;j<=n;j++)
    //            {
    //                printf("%d%c",dmin[i][j],j==n?'\n':' ');
    //            }
    //        }
    while (q--) {
      scanf("%d%d", &x, &y); /// 输入的是数的位置，记得减一
      printf("%d\n", rmq_max(x, y) - rmq_min(x, y));
    }
  }
  return 0;
}
