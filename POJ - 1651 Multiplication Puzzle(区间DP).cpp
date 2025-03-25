#include <algorithm>
#include <stdio.h> ///����DP
#include <string.h>
#define LL long long
using namespace std;
const int maxn = 108;
int n;
LL a[maxn],
    dp[maxn]
      [maxn]; /// DP[i][j]��ʾ��������ұ߽磬��ʾɾ�����ұ߽�֮�������Ҫ�Ļ���
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++)
      for (int j = 1; j + i <= n; j++) {
        dp[j][j + i] = 1e12;
        for (
            int k = j + 1; k < j + i;
            k++) /// ��һ��������ѡ��һ��kֵ�����kֵ�����ұ߽���ˣ���˼��ɾ��k�����Ҵӱ߽絽k�������������ȱ�ɾ������ͺ�ȡһ��������Сֵ
          dp[j][j + i] = min(dp[j][j + i],
                             a[j] * a[k] * a[j + i] + dp[j][k] + dp[k][j + i]);
        //                printf("dp[%d][%d] = %lld\n",j,j+i,dp[j][j+i]);
      }
    printf(
        "%lld\n",
        dp[1]
          [n]); /// �����Ϊֻ���µ�һ��ֵ�����һ��ֵ������������������ֵ��ɾȥ�����Ž⼴answer
  }
}
/*
6
10 1 50 50 20 5
7
10 1 50 50 20 100 20
*/
