#include <bits/stdc++.h>
using namespace std;
int main() {
  int len, n, a[100005];
  while (scanf("%d%d", &len, &n) != EOF) {
    if (len == 0 && n == 0)
      break;
    for (int i = 0; i < len; i++)
      scanf("%d", &a[i]);
    sort(a, a + len);
    int l = 1, r = 99999999;
    while (l <= r) /// 二分答案，符合条件为止
    {
      int mid = (l + r) / 2, pos = 0, cnt = 0;
      for (int i = 1; i < len; i++) {
        if (a[i] - a[pos] >= mid) {
          cnt++; /// 对符合条件的路段计数
          pos =
              i; /// 并且记录符合条件的位置，以便下一次找到这个位置继续往后接上
        }
      }
      if (cnt >= n - 1)
        l = mid + 1;
      else
        r = mid - 1;
      //            printf("----%d  %d  %d  %d\n",l,r,mid,cnt);
    }
    printf("%d\n",
           r); /// 因为是左边界大于右边界时才结束二分，因此是右边界位最终结果
  }
}
