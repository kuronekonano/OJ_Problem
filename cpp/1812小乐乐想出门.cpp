#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int n;
int a[1005][1005];
int dp[1005][1005];
int main() {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    memset(dp, 0, sizeof(dp)); // �������
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (i = 1; i < n; i++) // ����߽�
    {
      dp[i][0] =
          a[i][0] +
          dp[i - 1][0]; // ��Ϊֻ�����»������ߣ��߽�ֻ�ܴ�һ�������ۼӻ�ý��
      dp[0][i] = a[0][i] + dp[0][i - 1];
    }
    for (i = 1; i < n; i++) {
      for (j = 1; j < n; j++) {
        dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]); // �ݹ��ۼ�
      }
    }
    printf("%d\n", dp[n - 1][n - 1]);
  }
  return 0;
}
