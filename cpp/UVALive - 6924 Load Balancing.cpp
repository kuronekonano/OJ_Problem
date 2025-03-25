#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
  int t, mark[168], sum[168], cas = 0;
  scanf("%d", &t);
  while (t--) {
    int tmp;
    double n;
    memset(mark, 0, sizeof(mark));
    memset(sum, 0, sizeof(sum));
    scanf("%lf", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      mark[tmp]++; /// ͬ������������
    }
    sum[0] = mark[0]; /// ��������������ͣ���һ��������Ϊ���Ƴ�ֵ�ȸ�ֵ��
    for (int i = 1; i <= 160; i++) {
      sum[i] = sum[i - 1] + mark[i];
    }
    n /= 4;
    double ans = 0x7fffffff;
    int a, b, c;
    for (int i = 0; i <= 160; i++) {
      for (int j = i + 1; j <= 160; j++) {
        for (int k = j + 1; k <= 160; k++) {
          if (ans > fabs(n - sum[i]) + fabs(n - sum[j] + sum[i]) +
                        fabs(n - sum[k] + sum[j]) +
                        fabs(n - sum[160] + sum[k])) {
            ans = fabs(n - sum[i]) + fabs(n - sum[j] + sum[i]) +
                  fabs(n - sum[k] + sum[j]) +
                  fabs(n - sum[160] + sum[k]); /// ��¼�����ܺ���Сֵ
            a = i, b = j, c = k;
          }
        }
      }
    }
    printf("Case %d: %d %d %d\n", ++cas, a, b, c);
  }
}
