#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main() {
  int a[508][509], i, j, n, m,
      num[100000]; /// �ھ����У�һ��ʼ��Ҫ��Ҫ�ж�������ǲ�������
  bool su
      [100008]; /// �����ҳ�10^5�����е�����(����ɸ)��Ȼ�����������ŵ�һ��num������
  memset(
      su, true,
      sizeof(
          su)); /// ������lower_bound�ҵ���һ�����ڵ��ھ�����ĳ����������������������������
  su[1] = false;
  int flag = 0;
  for (i = 2; i <= 100000; i++) {
    if (su[i]) {
      num[flag++] = i;
      for (j = i + i; j <= 100000; j += i) {
        su[j] = false;
      }
    }
  }
  while (scanf("%d%d", &n, &m) != EOF) {
    int minn = 0x7f7f7f7f; /// ��ÿ��ÿ�еĲ�������ͣ�ȡ��Сֵ������С������
    for (i = 1; i <= n; i++) {
      a[i][0] = 0;
      for (j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        int pos = lower_bound(num, num + flag, a[i][j]) -
                  num;                /// ���ڵ��ڵ�ij����������λ��
        a[i][j] = num[pos] - a[i][j]; /// ��������������
        a[i][0] += a[i][j];
      }
      if (a[i][0] < minn)
        minn = a[i][0]; /// ȡ��Сֵ
    }
    //        printf("------------------\n");
    //        for(i=1;i<=n;i++)
    //        {
    //            for(j=1;j<=m;j++)
    //            {
    //                printf("%d%c",a[i][j],j==m?'\n':' ');
    //            }
    //        }
    //        printf("------------------\n");
    for (i = 1; i <= m; i++) {
      a[0][i] = 0;
      for (j = 1; j <= n; j++) {
        a[0][i] += a[j][i];
      }
      if (a[0][i] < minn)
        minn = a[0][i];
    }
    printf("%d\n", minn);
  }
}
