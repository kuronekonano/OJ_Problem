#include <stdio.h> ///�൱�ڰ�����������г�����
int main() {
  int a[205][208], n, i, j, h, l;
  while (scanf("%d", &n) != EOF) {
    int sum, flag = 0;
    for (i = 1; i <= n; i++) /// ��ά����������
    {
      sum = 0;
      for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        sum = sum + a[i][j]; /// ���ÿ��
      }
      a[i][0] = sum;    /// ��1��ʼ����0λ���Դ���һ�еĺ�
      if (sum % 2 != 0) /// ��Ϊż������
      {
        h = i;
        flag++;
      }
    }
    if (flag >= 2) /// ���ڵ���2ֱ��pass
    {
      printf("NO\n");
      continue;
    }
    int flag2 = 0;
    for (j = 1; j <= n; j++) {
      sum = 0;
      for (i = 1; i <= n; i++) {
        sum = sum + a[i][j];
      }
      a[0][j] = sum;
      if (sum % 2 != 0) {
        l = j;
        flag2++;
      }
    }
    if (flag2 >= 2) {
      printf("NO\n");
      continue;
    }
    if (flag == flag2 && flag2 == 1) {
      printf("change(%d,%d)\n", h, l);
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
