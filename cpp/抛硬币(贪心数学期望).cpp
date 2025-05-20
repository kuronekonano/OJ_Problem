#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(double a, double b) /// 传参记得是浮点型
{
  return a > b; /// 从大到小排序
}
int main() {
  int n, m, i, j;
  double a[100][100];
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 0 && m == 0)
      break; /// 都为0时退出
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%lf",
              &a[j][i]); /// 输入，将列变成行，行变成列输入，这样方便sort每一列
      }
    }
    double sum = 0; /// 初始化求和(数学期望)
    for (i = 0; i < m; i++) {
      sort(a[i], a[i] + n,
           cmp); /// 对每一列排序，那么每一行的元素都是那一列的最大值
    }
    for (i = 0; i < n; i++) /// 求和
    {

      double tmp = 1.0;
      for (j = 0; j < m; j++) {
        tmp *= a[j][i]; /// 每一项(行)的概率相乘
      }
      sum += tmp; /// 相加
    }
    //        for(i=0; i<m; i++)
    //        {
    //            for(j=0; j<m; j++)
    //            {
    //                printf(" %f",a[i][j]);
    //            }
    //            printf("\n");
    //        }
    printf("%.4f\n", sum); /// 数学期望的最大值
  }
  return 0;
}
