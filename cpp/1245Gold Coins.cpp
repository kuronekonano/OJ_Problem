#include <stdio.h>
int main() {
  int n, i, sum, kuro, coin;
  while (scanf("%d", &n) != EOF) // 1 4 9 16
  {
    if (n == 0) {
      return 0;
    }
    sum = 0;
    coin = 0;
    kuro = 0;
    for (i = 1; i <= n; i++) // ��1��ʼ���ӣ�ֱ��n
    {
      sum = i + sum; // ������
      if (sum > n)   // �������ʹ�����������
      {
        kuro = n - (sum -
                    i); // ��ȥ��ӵ���������n��ȱ�ٵ���������i���ʾ���������
        break;
      }
      coin = coin + i * i; // �������ֵ��������ý��
    }
    coin = coin + i * kuro; // ���϶���Ĳ���i��������õĽ��
    printf("%d %d\n", n, coin);
  }
  return 0;
}
