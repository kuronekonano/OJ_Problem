#include <stdio.h>
int gys(int a, int b) // ���õݹ鷽�������Լ��
{
  if (a % b == 0) {
    return b;
  } else {
    return gys(b, a % b);
  }
}
int gbs(int x, int y) // ��С������
{
  return (x * y) / gys(x, y); // �����˻��������Լ��������С������
}
int main() {
  int n, a, b, i, j, c[10];
  while (
      scanf("%d%d%d", &n, &a, &b) !=
      EOF) // �ҳ���a��b��Χ����ͬʱ��n����������������������n�����Ĺ�������ͬʱҲ��n������С�������ı���
  {
    for (i = 0; i < n; i++) {
      scanf("%d", &c[i]);
    }
    int sum = gbs(c[0], c[1]); // ���ҳ�����������С������
    for (i = 2; i < n; i++) {
      sum = gbs(sum, c[i]); // ��ѭ���ҳ�����������С������
    }
    i = 1;
    int flag = 0;
    while (i * sum >= a && i * sum <= b) // �ҵ�������С��������a��b��Χ�ڵı���
    {
      i++;
      flag++;
    }
    printf("%d\n", flag);
  }
  return 0;
}
