#include <algorithm>
#include <stdio.h> ///最长公共子序列
#include <string.h>
using namespace std;
int vis[1008][1009], i, j, t;
int main() {

  char x[1005];
  char y[1004];
  scanf("%d", &t);
  while (t--) {
    scanf(
        "%s %s", x + 1,
        y + 1); // 为方便对数组中每个位置的元素计数，输入字符串从首地址位置+1开始
    int lx = strlen(x + 1);
    int ly = strlen(y + 1);
    for (i = 1; i <= lx; i++) {
      vis[i][0] =
          i; // 第几个字符就是和0位相比，增添几次，所以次数刚好是字符的位置编号
    }
    for (i = 1; i <= ly; i++) {
      vis[0][i] = i;
    }
    vis[0][0] = 0; // 初始值都是为0
    for (i = 1; i <= lx; i++) {
      for (
          int j = 1; j <= ly;
          j++) // 动态规划,一个一个字符比较，若相同，则继承之前的次数，不同，则从三种变换中筛选最优解
      {
        if (x[i] == y[j]) // 一直累加到最后是最终变化结果
        {
          vis[i][j] = vis[i - 1][j - 1]; // 继承
        } else {
          vis[i][j] = vis[i - 1][j - 1] + 1; // 变换
        }
        vis[i][j] = min(
            vis[i - 1][j] + 1,
            min(vis[i][j],
                vis[i][j - 1] +
                    1)); // 三种情况，插入（增加）、删减、变换，从中取最优解（改变次数最少的）
        //                vis[i][j]=min(vis[i][j-1]+1,vis[i][j]);
      }
    }
    printf("%d\n", vis[lx][ly]);
  }
  return 0;
}
