#include <stdio.h>
int main() {
  int t, n, a[56];
  scanf("%d", &t); // ������Ϊn�������ߵ�ñ��Ϊm
  while (
      t--) // ʣ�µ�ñ��Ϊn-m�������ñ�ӵ��˿�����ñ������Ϊn-m-1��û��ñ�ӵ��˿�����ñ������Ϊn-m
  {
    int sum =
        0; // n-mΪ����ñ�ӵ�������mΪû��ñ�ӵ�������(n-m)*(n-m-1)+m*(n-m)=sum
    scanf("%d", &n); //(n-m)*(n-1)=sum
    for (int i = 1; i <= n;
         i++) // �����˿�����ñ������sumһ��Ϊʣ��ñ��������n-1��
    {
      scanf("%d", &a[i]);
      sum = sum + a[i];
    }
    if (sum % (n - 1) == 0) {
      printf("%d\n", sum / (n - 1));
    } else
      printf("-1\n");
  }
  return 0;
}
