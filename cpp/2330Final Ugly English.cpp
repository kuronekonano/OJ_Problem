#include <stdio.h>
#include <string.h>
int main() {
  char a[1008], b[1008];
  int i;
  while (gets(a)) {
    int n = strlen(a);
    int flag = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != ' ') {
        b[flag++] = a[i];
      } else /// �ٴ������ո��ʱ����Ϊflag����ʼ��Ϊ0�ˣ�������������ĸǰ����������
      {
        for (int j = flag - 1; j >= 0; j--) {
          printf("%c", b[j]);
        }
        flag = 0;
        printf("%c", a[i]); /// �ѿո������
      }
    }
    for (i = flag - 1; i >= 0; i--) /// ���һ������
    {
      printf("%c", b[i]);
    }
    printf("\n");
  }
  return 0;
}
