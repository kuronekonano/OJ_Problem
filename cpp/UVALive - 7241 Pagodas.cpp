#include <stdio.h> ///��Ϊ������j�Ӽ�k�õ���ֵ��������õ��µ�ֵ�Թ��ó������ֵ��������õ�һ���Ȳ����У�����Ȳ����еĹ���ǳ�ʼ���������Լ��
int gcd(
    int a,
    int b) /// ������Լ�������Ϊ1��(��������)�����ǹ���Ϊ1�Ŀɽ������У�����������n/���������Խ������������ж���ż���ɵ�֪˭Ӯ
{
  int c;
  while (b != 0) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
int main() {
  int t, i, n, a, b, cas = 0;
  scanf("%d", &t);
  while (t--) {
    cas++;
    scanf("%d%d%d", &n, &a, &b);
    int c = gcd(a, b);
    if ((n / c) % 2 == 0)
      printf("Case #%d: Iaka\n", cas);
    else {
      printf("Case #%d: Yuwgna\n", cas);
    }
  }
}
