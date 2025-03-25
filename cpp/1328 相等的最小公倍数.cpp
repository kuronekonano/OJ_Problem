#include <stdio.h>
#include <string.h> ///����ҹ��ɣ����֣�����������ΪNO,����������n�η���NO
bool a[1000008];
int b[1000008];
int main() {
  int t, n, num = 0;
  memset(a, true, sizeof(a));
  for (int i = 2; i <= 1000000; i++) {
    if (a[i]) {
      b[num++] = i;
      for (int j = i + i; j <= 1000000; j += i) {
        a[j] = false;
      }
    }
  }
  for (int i = 0; i < num; i++) {
    if (b[i] >= 1000)
      break;
    for (int j = b[i]; j <= 1000000; j = j * b[i])
      a[j] = true;
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (a[n])
      printf("NO\n");
    else
      printf("YES\n");
  }
}
