#include <stdio.h> ///������ݼ������С�dp
#include <string.h>
int main() {
  int a[1005], dp[1008], n, i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp)); /// �ǵ����
    dp[0] = 1;
    int flag;
    for (i = 1; i < n; i++) {
      flag = dp[i];
      for (j = 0; j < i; j++) {
        if (a[i] < a[j] &&
            flag < dp[j]) /// ���������ﲻС�İ�dp��������a����
        {
          flag = dp[j];
        }
      }
      dp[j] = flag + 1;
    }
    int maxn = dp[0];
    for (i = 0; i < n; i++) /// �Ժ���for�����ֵ�ɡ��Ͼ�ֻ�ñ���һ��
    {
      if (dp[i] > maxn) {
        maxn = dp[i];
      }
    }
    printf("%d\n", n - maxn); /// ������ܸ�����ȥ����г��ȼ��Ǳ�ɾ����С����
  }
  return 0;
}
