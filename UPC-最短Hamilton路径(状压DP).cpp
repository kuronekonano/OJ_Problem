#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int dp[(1 << 20) + 10][maxn];
int n, a[maxn][maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    dp[1][1] = 0;
    for (int i = 1; i < (1 << n); i++) /// �������п���״̬
      for (int j = 1; j <= n; j++)
        if ((i >> (j - 1)) & 1) /// ��ÿһ��״̬�����Ǽ��㾭��j�е���̾���
          for (
              int k = 1; k <= n;
              k++) /// ���㾭��j�е���̾�����Ҫ����k�е���̾�����ϣ���k��j�о���
            if ((i >> (k - 1)) & 1)
              dp[i][j] = min(dp[i][j], dp[i ^ (1 << (j - 1))][k] + a[k][j]);
    printf("%d\n",
           dp[(1 << n) - 1][n]); /// �������������г����ҵ���n�е���̾���
  }
}
/// dp[i][j]��ʾ��1�����������������i״̬��λΪ1�����г��У�����j����̾���
