#include <stdio.h>
using namespace std;

int main() {
  int t, n, m, i, j, mark, flag1, flag2;
  scanf("%d", &t); // ��T������
  while (t--) {
    scanf("%d%d", &n, &m);   // ����ѧ�������Ϳγ�����
    flag2 = 0;               // ��ʼ������ѧ������������
    for (i = 1; i <= n; i++) // ����ÿ��ѧ���ķ���
    {
      flag1 = 0;               // ��ʼ������80�ֿ�Ŀ������
      for (j = 1; j <= m; j++) // ����Ŀγ���
      {
        scanf("%d", &mark); // ����ѧ������
        if (mark > 80) {
          flag1++;
        }
      }
      if (flag1 > 3) // ���ﵽ3�ſγ�����������ѧ������������
      {
        flag2++;
      }
    }
    printf("%d\n", flag2);
  }
  return 0;
}
