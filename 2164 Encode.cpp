#include <stdio.h>
#include <string.h> ///˼·����һ��4*4�ÿո���յľ��������ÿ���ַ���Ȼ���ٵ��Ż�ȥ����������һ�����ټ���װʣ�µģ����������װ��ֱ���ַ�������
int main() {
  char a[108];
  int i, j, k;
  while (gets(a)) {
    int n = strlen(a);
    bool flag = false;
    for (i = 0; i < n;) {
      char b[5][5];
      memset(b, ' ', sizeof(b));
      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          b[j][k] = a[i++];
          if (i == n) {
            flag = true;
            break;
          }
        }
        if (flag)
          break;
      }
      for (j = 0; j <= 3; j++) {
        for (k = 3; k >= 0; k--) {
          printf("%c", b[k][j]);
        }
      }
    }
    printf("\n"); /// �ǵû���
  }
}
