#include <stdio.h>            ///����ȫ����
#include <string.h>           ///next_permutation(a,a+m)ȫ����
int vis[30];                  /// �������
int a[35];                    /// �ݹ�����
int b[35], nums[780][10], ii; /// ���nΪ6,6�Ľ׳�����������720����ÿ����6������
int dfs(int n, int num) {
  if (num > n) /// ��num�����ִ�������n�ĸ���ʱ��˵�������ˣ����Լ�¼��ǰ������
  {
    ii++;
    for (int i = 1; i <= n; i++) /// ��¼a�����е���n����
    {
      nums[ii][i] = a[i];
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) /// ��û�б����(�����������Ƿ���ȫ�ֱ����ģ����Ե�һ��for������1���ڶ��ξ���2��������)
    {
      vis[i] = 1; /// ��������
      a[num] = i;
      //            for(int k=1; k<=n; k++)printf("%d\n",vis[k]);
      //            printf("======\n");
      dfs(n, num + 1); /// �ݹ�
      vis[i] = 0;
    }
  }
}
int main() {
  int n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    memset(vis, 0, sizeof(vis));
    ii = 0;
    dfs(n, 1);
    int j;
    int flag = 1;
    for (int i = 1; i <= ii; i++) {
      for (j = 1; j <= n; j++) {
        if (b[j] != nums[i][j])
          break;
        //                  printf("%d%c",nums[i][j],j==n?'\n':' ');
      }
      if (j == n + 1) {
        flag = i;
        break;
      }
    }
    if (flag == ii)
      flag = 0;
    for (int k = 1; k <= n; k++) {
      printf("%d%c", nums[flag + 1][k], k == n ? '\n' : ' ');
    }
  }
  return 0;
}
