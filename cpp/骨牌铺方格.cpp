#include <stdio.h>
int main() {
  long long n, kuro[55], i;
  while (scanf("%lld", &n) != EOF) {
    kuro[1] = 1; // ����̨������һ����һ������ֻ����һ�ְڷ�
    kuro[2] = 2; // ������������Ժ���������ְڷ����Դ����ƣ�1��2�ۼӰڷ�
    for (i = 3; i <= n; i++) {
      kuro[i] = kuro[i - 1] + kuro[i - 2];
    }
    printf("%lld\n", kuro[n]);
  }
  return 0;
}
