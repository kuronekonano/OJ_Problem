#include <stdio.h>
#include <string.h>
int main() {
  int i, s, v, a, g, x;
  char n[55];
  while (scanf("%s", &n) != EOF) {
    v = 0;
    a = 0;
    g = 0;
    s = strlen(n);
    for (i = 0; i < s; i++) {
      if (n[i] == 'v') {
        v++;
      }
      if (n[i] == 'a') {
        a++;
      }
      if (n[i] == 'g') {
        g++;
      }
    }
    if (v >= g) // ����ͳ��v�໹��g�࣬�����ٵ���,�����˵������
    {
      x = g;
    } else if (v < g) {
      x = v;
    }
    if (a / 3 < x) // ��a/3���٣�����a�㣬������v��g��
    {
      x = a / 3;
    }
    printf("THE NUMBER 1S %d.\n", x);
  }
  return 0;
}
