#include <stdio.h>  ///不允许有一个以上最高的人
#include <string.h> ///从左到右以及从右到左分别求出最长递增子序列，不能用nlogn的方法，因为目的是要得到从0到达某个数字位的最长递增长度
int main() /// 从两头各走一边最长递增子序列后，每个数字的maxn[i]和minn[i]都将表示从左到右
{
  int n, a[105], maxn[105], minn[105];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    memset(maxn, 0, sizeof(maxn));
    memset(minn, 0, sizeof(minn));
    maxn[0] = 1;
    minn[n - 1] = 1;
    for (int i = 1, x = n - 2; i < n; i++, x--) {
      int flag = 0, flag2 = 0;
      for (int j = 0; j < i; j++)
        if (a[i] > a[j] && maxn[j] > flag)
          flag = maxn[j];
      maxn[i] = flag + 1;
      for (int j = n - 1; j > x; j--)
        if (a[x] > a[j] && minn[j] > flag2)
          flag2 = minn[j];
      minn[x] = flag2 + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (ans < maxn[i] + minn[i] - 1)
        ans = maxn[i] + minn[i] - 1;
    printf("%d\n", n - ans);
  }
}
