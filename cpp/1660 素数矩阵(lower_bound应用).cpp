#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main() {
  int a[508][509], i, j, n, m,
      num[100000]; /// 在矩阵中，一开始想要不要判断这个数是不是素数
  bool su
      [100008]; /// 首先找出10^5内所有的素数(素数筛)，然后将所有素数放到一个num数组中
  memset(
      su, true,
      sizeof(
          su)); /// 再利用lower_bound找到第一个大于等于矩阵内某个数的素数，做差可算出操作距离
  su[1] = false;
  int flag = 0;
  for (i = 2; i <= 100000; i++) {
    if (su[i]) {
      num[flag++] = i;
      for (j = i + i; j <= 100000; j += i) {
        su[j] = false;
      }
    }
  }
  while (scanf("%d%d", &n, &m) != EOF) {
    int minn = 0x7f7f7f7f; /// 对每行每列的操作数求和，取最小值便是最小操作数
    for (i = 1; i <= n; i++) {
      a[i][0] = 0;
      for (j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        int pos = lower_bound(num, num + flag, a[i][j]) -
                  num;                /// 大于等于第ij个数的素数位置
        a[i][j] = num[pos] - a[i][j]; /// 做差计算操作距离
        a[i][0] += a[i][j];
      }
      if (a[i][0] < minn)
        minn = a[i][0]; /// 取最小值
    }
    //        printf("------------------\n");
    //        for(i=1;i<=n;i++)
    //        {
    //            for(j=1;j<=m;j++)
    //            {
    //                printf("%d%c",a[i][j],j==m?'\n':' ');
    //            }
    //        }
    //        printf("------------------\n");
    for (i = 1; i <= m; i++) {
      a[0][i] = 0;
      for (j = 1; j <= n; j++) {
        a[0][i] += a[j][i];
      }
      if (a[0][i] < minn)
        minn = a[0][i];
    }
    printf("%d\n", minn);
  }
}
