#include <stdio.h>
bool tab(int a, int b) /// ����ת�����ж�
{
  if (a % b == 0) /// ����պ��ǵ�ǰ������������������ôһ�����ǻ�����
  {
    return false;
  }
  int c[108] = {0}, k = 0;
  while (a) /// ת�����ƾ�������ͳ��Ĺ���
  {
    c[k++] = a % b; /// ������������У�����������Ӧ���Ƶı�ʾ����
    a = a / b;
  }
  for (int i = 0, j = k - 1; i < j; i++, j--) /// ��������͵�������ĶԱ�
  {
    if (c[i] != c[j]) /// ���в�ֱͬ�ӷ��ز�����
    {
      return false;
    }
  }
  return true; /// ȫ��˳����������
}
bool play(int x) /// �жϺ��������ж��Ƿ����2�ֽ��ƿɻ���
{
  int sum = 0;                  /// ��������ʼ��
  for (int i = 2; i <= 10; i++) /// �жϴ�2��10����
  {
    if (tab(x, i)) /// �ж��Ƿ�������ĵĺ���
    {
      sum++; /// ����
    }
  }
  if (sum >= 2) /// �ж��Ƿ��������
  {
    return true;
  } else {
    return false;
  }
}
int main() {
  int n, s, flag = 1;
  while (scanf("%d%d", &n, &s) != EOF) {
    printf("Case %d:\n", flag++);
    int v = 0;    /// ��ʼ��������
    s++;          /// ��ס���⣬�Ӵ��ڣ������ʼ
    while (v < n) /// ��whileѭ������������forѭ����GG
    {
      if (play(s)) /// ��s��ʼ���жϺ���
      {
        printf("%d\n", s); /// ���������
        v++;
      }
      s++; /// s����
    }
  }
  return 0;
}
