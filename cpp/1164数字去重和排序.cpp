#include <stdio.h> //�ǳ���Χ������ȥ��
#include <string.h>
int a[910305]; // �������
int main() {
  int n, flag, i, j;
  while (scanf("%d", &n) != EOF) // n������
  {
    memset(a, 0, sizeof(a)); // ��ձ������
    flag = 0;                // ����������
    for (i = 0; i < n; i++)  // ѭ������
    {
      scanf("%d", &j);
      if (!a[j])
        flag++; // ������һ����δ����ǣ����������һ
      a[j]++;   // ������������ֳ��ִ���
    }
    printf("%d\n", flag); // ������������
    bool one = false;     // ���������ڿ��ƿո�
    for (
        i = 0; i < 910306;
        i++) // ����������飬����������ǵ�������Ǹ�������Ϊ���ֻ���Ƿ����������������ظ������������и���Ԫ�����ź����
    {
      if (a[i]) // �������˱�ǵ�Ԫ�أ������
      {
        if (one == false) {
          printf("%d", i);
          one = true;
        } else
          printf(" %d", i);
      }
    }
    printf("\n");
  }
  return 0;
}
