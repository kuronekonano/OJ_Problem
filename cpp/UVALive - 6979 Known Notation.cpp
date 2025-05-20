#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int n, i, t, j, pos[2008];
  char a[5008];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    n = strlen(a);
    int num = 0, mul = 0, ans = 0;
    for (i = 0; i < n; i++) {
      if (a[i] >= '0' && a[i] <= '9') {
        num++;
      } else
        mul++;
    }
    if (mul == 0) {
      printf("0\n");
      continue;
    }
    if (num <= mul) {
      ans += mul - num + 1;
      int j = n - 1;
      for (i = ans + n - 1; i >= ans; i--) {
        a[i] = a[j--];
      }
      for (i = 0; i < ans; i++) {
        a[i] = '1';
      }
      a[ans + n] = '\0';
      n = strlen(a);
    }
    mul = 0;
    num = 0;
    for (i = n - 1; i >= 0; i--) {
      if (a[i] != '*')
        pos[mul++] =
            i; /// 要换的是后面的数字，把后面的数字放到前面，前面的星号放到后面，所以从后记录要交换的数字的位置
    }
    mul = 0, j = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == '*')
        mul++;
      if (a[i] >= '0' && a[i] <= '9')
        num++;
      //            printf("%c===%d %d\n",a[i],mul,num);
      if (mul >= num) {
        swap(a[i], a[pos[j++]]);
        ans++;
        mul--;
        num++;
      }
    }
    if (a[n - 1] != '*')
      ans++;
    printf("%d\n", ans);
  }
}
