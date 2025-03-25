#include <map>
#include <math.h>
#include <stdio.h> ///一层层提高海平面，逐渐淹没最低陆地，每次淹没作为一轮岛屿计数
#include <string.h>
using namespace std;
int k, a[20], t;
bool check() /// 判断是否所有岛屿都被淹没
{
  for (int i = 2; i <= 11; i++) {
    if (a[i])
      return false;
  }
  return true;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &k);
    for (int i = 1; i <= 12; i++)
      scanf("%d", &a[i]);
    int sum = 0, num = 2;
    while (!check()) /// 头尾一定是0
    {
      int i = 2; /// 不断从2遍历到11
      while (i <= 11) {
        if (a[i] && a[i - 1] == 0) /// 只要不是0(海面)
        {
          sum++;                 /// 作为岛屿开始，计数增长
          int minn = 0x7fffffff; /// 记录每个整体岛屿最低点
          int st = i;            /// 记录岛屿开始位置
          while (a[i] != 0)      /// 遍历到海面
          {
            if (a[i] < minn)
              minn = a[i];
            i++;
          }
          for (int j = st; j <= i; j++)
            if (a[j])
              a[j] -= minn; /// 重遍历淹没最低点
        }
        i++; /// 越过当前是海域的位置
      }
    }
    printf("%d %d\n", k, sum);
  }
}
