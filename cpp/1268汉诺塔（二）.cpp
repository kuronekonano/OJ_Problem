#include <stdio.h>
long long tower(int a) /// ��ŵ��������63�ڿ���long long���£�����ȡ������
{
  long long flag = 1;
  for (int i = 1; i < a; i++) {
    flag = flag * 2 + 1; /// ��ŵ�����ƹ�ʽ
  }
  return flag; /// ����ֵ��long long��
}
int main() {
  int i, n;
  while (scanf("%d", &n) != EOF) {
    long long hano = tower(n); /// �ɴ�������ģ���ٳ����������ʱ����
    int second = hano % 60;
    hano = hano / 60;
    int minute = hano % 60;
    hano = hano / 60;
    int hour = hano % 24;
    hano = hano / 24;
    int day = hano % 365;
    hano = hano / 365;
    printf("%lld years %d days %d hours %d minute %d seconds\n", hano, day,
           hour, minute, second);
  }
  return 0;
}
