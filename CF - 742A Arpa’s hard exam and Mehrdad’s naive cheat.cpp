#include <stdio.h> ///1378��n�η������һλ�������һֱ��10ȡ��ȡ��λ��8�ͺ�
int main() /// ��forѭ�������Ϊ��1e9Ҳ�ᳬʱ���й��ɵģ�8  6  4 2,���ȡ��n�ͺ�
{
  int n, a[5] = {6, 8, 4, 2, 6};
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      printf("1\n");
      continue;
    }
    printf("%d\n", a[n % 4]);
  }
}
