#include <stdio.h>
#include <string.h>
int main() {
  int n, m, i, j, x, y, k;
  bool vis[105][108];
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(vis, false, sizeof(vis)); /// ����ǵ��������
    for (i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      vis[x][y] = true; /// �����н�����ϵ
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        for (k = 1; k <= n; k++) {
          if (vis[i][j] == true &&
              vis[j][k] ==
                  true) /// �����Ƚϣ�����Ӧ��ϵ����������ֱ���������ע��ϵ
          {
            vis[i][k] = true;
          }
        }
      }
    }
    vis[1][1] = true; /// ��һ���ǿ϶��е�
    int flag = 0;     /// ������
    for (i = 1; i <= n; i++) {
      if (vis[1][i] == true) /// ֱ������1����ֱ�ӹ�ϵ��
        flag++;
    }
    printf("%d\n", flag);
    //        for(i=1;i<=n;i++)
    //        {
    //            for(j=1;j<=n;j++)
    //            {
    //                printf("%d",vis[i][j]);
    //            }
    //            printf("\n");
    //        }
  }
  return 0;
}
