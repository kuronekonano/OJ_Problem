#include <stdio.h>
int main() {
  int t, i, j, n, a[305][305];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int m, x1, y1, x2, y2;
    scanf("%d", &m);
    while (m--) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2); /// ��������ȷ���ĳ�����
      int max = a
          [x1]
          [y1]; /// �����ֵ��ֱ������ѭ��Ƕ�ף���ʼ�ͽ���������պ����ṩ�ĳ��������귶Χ
      for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
          if (max < a[i][j]) {
            max = a[i][j];
          }
        }
      }
      printf("%d\n", max);
    }
  }
  return 0;
}
