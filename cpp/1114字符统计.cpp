#include <stdio.h>
#include <string.h>

using namespace std;
int main() {
  int n, t, i, j;
  while (scanf("%d", &t) != EOF) {
    if (t == 0)
      return 0;
    while (t--) {
      char a[1008];
      int s[30];
      memset(s, 0, sizeof(s));
      scanf("%s", a);
      n = strlen(a);
      for (i = 0; i < n; i++) {
        s[a[i] -
          'a']++; /// 数组的每个元素代表一个字母出现的次数，而且是固定的，sort无法排序
      }
      int big = s[0], b = 0;
      for (i = 0; i < 26; i++) // 找出现最大次数的循环
      {
        if (s[i] > big) {
          big = s[i];
          b = i;
        }
      }
      printf("%c\n", b + 'a');
    }
  }
  return 0;
}
