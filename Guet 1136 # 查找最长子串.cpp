#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int t, i, j;
  char a[10005];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    int dp[10008];
    memset(dp, 0, sizeof(dp));
    int flag;     /// ��ʱ���ֵ��ţ��ҳ���ǰ�������ַ�֮ǰ�������ַ��������
    int maxn = 1; /// ����ȼ�¼��Ҳ����ans
    dp[0] = 1;    /// ��1���ַ�����Ϊ1
    int n = strlen(a);
    for (i = 1; i < n; i++) {
      flag = dp[i];
      for (j = 0; j < i; j++) {
        if (a[i] > a[j] && dp[j] > flag) {
          flag = dp[j];
        }
      }
      dp[i] = flag + 1;
      maxn = max(maxn, dp[i]);
    }
    printf("%d\n", maxn);
  }
}
