#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char a[25];
  while (scanf("%s", a) != EOF) {
    long n =
        strtol(a, NULL, 12); /// ת�� 12���Ƶ�ʮ���ƣ�ͷ�ļ����⣬ֱ��ȡ������
    printf(n % 11 == 0 ? "YES\n" : "NO\n");
  }
  return 0;
}
