#include <stdio.h>
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) // ��һ��ͼ��ֻ��һ��
  {
    int sum = 1; // �ڶ���ͼ����Χ������12��
    for (i = 2; i <= n; i++) {
      sum = sum + (i - 1) * 12;
    }
    printf("%d\n", sum);
  }
  return 0;
}
