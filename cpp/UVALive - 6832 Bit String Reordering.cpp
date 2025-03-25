#include <algorithm>
#include <stdio.h>
using namespace std;
int change(
    int a[], int b[], int i,
    int j) /// dfs交换,找到一个和标准序列中相同的数字后，回溯调换，并记录步数
{
  int ans = 0;
  if (a[i] == b[j])
    return ans;
  else {
    ans += change(
        a, b, i + 1,
        j); /// 当与当前位不同时，选择下一位，直到找到相同的，这个不同位是交换的路径上的一步，计数
    swap(a[i + 1], a[i]); /// 已经找到一样的位数时，就回溯交换
    return ans + 1;       /// 返回结果加当前步数
  }
}
int main() {
  int n, m, a[20], judge[20],
      check
          [20]; /// a为原序列。judge为一种1开头的标准序列，check为以0开头的标准序列
  while (scanf("%d%d", &n, &m) != EOF) {
    int num =
        0; /// 记录1的个数，当1和0的个数相同时才会两种序列情况都要比较并计算步骤，取最小值，否则只用比较一种和输入串一样的标准串
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i])
        num++;
    }
    int tmp,
        it = 0, flag = 0, nn = 0,
        uu =
            0; /// it为记录指针，后移至n，nn为以0开头的标准串中1的个数，uu是以1为标准串中1的个数
    for (int i = 0; i < m; i++) {
      scanf("%d", &tmp);
      while (tmp--) /// 构造标准串
      {
        check[it] = flag;
        judge[it++] = !flag;
        if (flag)
          nn++;
        else
          uu++;
      }
      flag = !flag;
    }
    int b[20];
    for (int i = 0; i < n; i++)
      b[i] = a
          [i]; /// 当1和0的个数相同时，将要比较两个串，因为第一个串已经比较并交换成标准串，所以要存储初始串
    int ansn = 0, ansu = 0; /// 两个ans
    if (nn == num)
      for (int i = 0; i < n; i++)
        if (a[i] != check[i])
          ansn += change(a, check, i, i);
    if (uu == num)
      for (int i = 0; i < n; i++)
        if (b[i] != judge[i])
          ansu += change(b, judge, i, i);
    if (nn == uu)
      ansn = ansn < ansu ? ansn
                         : ansu; /// 如果1和0个数相同，比较两个形式后取最小步数
    else
      ansn =
          ansn < ansu
              ? ansu
              : ansn; /// 否则只存在一种答案，另一个ans因为没有跑，所以还是初始值0，取最大值就是跑了的答案
    printf("%d\n", ansn);
  }
}
