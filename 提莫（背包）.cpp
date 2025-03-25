#include <algorithm>
#include <stdio.h> ///����
#include <string.h>
using namespace std;
struct metal /// ��ֵ�͹������
{
  int att;
  int vol;
} timo[1005];
int dp[1005][1005]; /// dp����
int main() {
  int i, n, v, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &v); /// n�����ߣ�v������
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++) /// �����ֵ�͹���,n������
    {
      scanf("%d", &timo[i].att);
    }
    for (i = 1; i <= n; i++) {
      scanf("%d", &timo[i].vol);
    }
    for (i = timo[1].vol; i <= v; i++) /// �߽��ʼ����
    {
      dp[1][i] = timo[1].att; /// ��̬�滮���ĺ����Ǵ�1��ʼ����ı�������
    }
    for (i = 2; i <= n; i++) {
      for (int j = 1; j <= v; j++) {
        if (j >= timo[i].vol) {
          dp[i][j] =
              max(dp[i - 1][j], dp[i - 1][j - timo[i].vol] + timo[i].att);
        } else
          dp[i][j] = dp[i - 1][j];
      }
    }
    printf("%d\n", dp[n][v]);
  }
  return 0;
}
