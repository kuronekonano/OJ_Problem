#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int a[109], i, n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      return 0;
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a,
         a + n); /// 排序后方便找到人数较少的州，这样才能达到获取选票最少的目的
    int sum = 0; /// 计数器
    if (n % 2 ==
        0) /// 必须分类讨论，奇数州和偶数州数，当奇数州数时，过半只需+1再除2,偶数州数时，为了过半，除2后还需加1
    {
      for (i = 0; i < n / 2 + 1; i++) {
        sum = sum + (a[i] + 1) / 2; /// 同理，每个州人数过半也分奇偶性
        if (a[i] % 2 ==
            0) /// 首先+1再除2，奇数肯定过半，而如果是偶数，则刚好达到一半，判断是否是偶数，若是偶数则再加一达到过半
        {
          sum++;
        }
      }
    }
    if (n % 2 != 0) {
      for (i = 0; i < (n + 1) / 2; i++) {
        sum = sum + (a[i] + 1) / 2;
        if (a[i] % 2 == 0) {
          sum++;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
