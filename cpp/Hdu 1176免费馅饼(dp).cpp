#include <algorithm>
#include <stdio.h>
#include <string.h> ///其实就是普通的数塔模型
using namespace std;
int dp[100005][15]; /// 二维数组中横坐标为位置，纵坐标为时间
int main() {
  int n, i, j, x, t;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp)); /// 记得清空数组
    int maxn = 0;
    for (i = 0; i < n; i++) {
      scanf("%d%d", &x, &t);
      dp[t]
        [x]++; /// 此处计数时直接用dp数组给输入的位置+1，表示某时刻某位置有几个馅饼(这是之前没想到的，根本没有用到递推的初始边界)
      maxn =
          maxn < t
              ? t
              : maxn; /// 因为纵坐标时间的最大值没有确定，因此在输入的过程中要不断取最大值判断时间从哪里开始遍历
    }
    for (
        i = maxn - 1; i >= 0;
        i--) /// 像数塔一样，从最后面的的倒数第二行开始dp,每次取上一行中能够接触到的三个位置的最大值，然后加上正在遍历的那个位置
    {
      dp[i][0] =
          max(dp[i + 1][0], dp[i + 1][1]) +
          dp[i]
            [0]; /// 特殊位置，最左边和最右边的边界0和10位置，只能单独继承上方的两个位置
      dp[i][10] = max(dp[i + 1][10], dp[i + 1][9]) + dp[i][10];
      for (j = 1; j <= 9; j++) {
        dp[i][j] = max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1])) +
                   dp[i][j]; /// 剩下的1到9都是继承上方三个位置
      }
    }
    printf("%d\n",
           dp[0][5]); /// 因为只能从0,5位置开始，因此直接输出0，5的dp结果
  }
  return 0;
}
