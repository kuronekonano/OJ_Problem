#include <stdio.h>
int a[2][13] = {
    0,  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0,
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// �������飬һ��ƽ��һ������
int rp(int x) {
  if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) /// ƽ���ж�
    return 1;
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int year, month, day, s, i, j, k;
    int maxday;
    scanf("%d-%d-%d", &year, &month, &day); /// �����ʼ������
    scanf("%d", &s);                        /// ��������
    int add = s / 86400;                    /// ���ӵ�����
    i = month;                              /// �·�
    j = day;                                /// ����
    while (add--)                           /// �����������μ���
    {

      j++;                 /// ��ʼ��������
      int flag = rp(year); /// �жϵ���ƽ��
      if (j > a[flag][i])  /// �� �����������ڵ����������ʱ
      {
        j = 1; /// ��ʼ����1��
        i++;   /// �·�����
      }
      if (i > 12) /// �ж��·ݴ���12ʱ��������ӣ���ʼ���·���
      {
        i = 1;
        year++;
      }
    }
    printf("%d-%02d-%02d\n", year, i, j);
  }
  return 0;
}
