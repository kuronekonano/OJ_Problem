#include <stdio.h>
#include <string.h>
int main() {
  int n, m, i, j, a[58][56], t, x[5] = {0, 1, 0, -1}, y[5] = {1, 0, -1, 0};
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    int sum = 0;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] != 0)
          sum++; /// ���ӽǣ��з�����е�λΪ1�ı����
      }
    }
    for (i = 1; i <= n;
         i++) /// ÿ��߶ȼ�ȥ��Χ�ĸ��ĸ߶ȣ������䱩¶�����ı����
    {
      for (j = 1; j <= m; j++) {
        if (a[i][j] != 0) {
          for (int k = 0; k < 4; k++) {
            if (a[i][j] > a[i + x[k]][j + y[k]]) {
              sum += a[i][j] - a[i + x[k]][j + y[k]];
            }
          }
        }
      }
    }
    printf("%d\n", sum);
  }
}
