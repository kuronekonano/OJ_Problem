#include <algorithm> ///reverse函数头文件
#include <stdio.h>
#include <string.h> ///此函数比直接用数组倒序输出费时，详见2330
using namespace std;
int main() {
  char a[10008], b[10008];
  int i, t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    gets(a);
    int n = strlen(a);
    int flag = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != ' ') {
        b[flag++] = a[i];
      } else {
        reverse(b, b + flag); /// 从某个位置至某个位置调转
        printf("%s", b);
        memset(b, 0, sizeof(b));
        printf("%c", a[i]);
        flag = 0;
      }
    }
    reverse(b, b + flag);
    printf("%s\n", b);
    memset(b, 0, sizeof(b)); /// 清空字符数组时，清为0也是完全空掉
  }
  return 0;
}
