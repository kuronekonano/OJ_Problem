#include <stdio.h>
int main() {
  int n, i, a, b;
  while (
      scanf("%d%d", &a, &b) !=
      EOF) // ��Ȼ�ò���pow����һ��һ����η�������forѭ���˻���ÿ�ζ�ȡ��λ����֤�����
  {
    n = 1;
    for (i = 1; i <= b; i++) {
      n = n * a;
      n = n % 10;
    }
    printf("%d\n", n);
  }
  return 0;
}
