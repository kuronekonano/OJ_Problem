#include <stdio.h>
#include <string.h>
int k, a[1508][1508];
int main() {
  bool vis[1508];
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, false, sizeof(vis));
    int tmp, n, m1, m2, m3;
    scanf("%d%d%d%d", &n, &m1, &m2, &m3);
    for (int i = 1; i <= m1; i++) /// ����1  �����ֵ��Ϊ��
    {
      scanf("%d", &tmp);
      vis[tmp] = true;
    }
    for (int i = 1; i <= m2;
         i++) /// ����2  �����յ�ans�жϣ���߶�����Ͳ�
              /// �Ľ��Ϊ�ռ���Ҳ����˵��ÿ�б�������һ��Ԫ���Ǽ�
    {
      scanf("%d", &a[i][0]);
      for (int j = 1; j <= a[i][0]; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    bool flag;
    for (
        int i = 1; i <= m3;
        i++) /// ����3
             /// �����Ϊ���Ԫ�ز����֪�ұߵ�Ԫ��Ϊ�棬����������ʱ�ж�ÿ��Ԫ�ص����
    {
      scanf("%d", &k);
      flag = true;
      for (int j = 1; j <= k; j++) {
        scanf("%d", &tmp);
        if (!vis[tmp])
          flag = false;
      }
      scanf("%d", &tmp);
      if (flag)
        vis[tmp] = true;
    }
    bool ans = true;
    for (int i = 1; i <= m2;
         i++) /// ����ж����Ͷ���ÿ������Ƿ��������һ�䲻��������ΪNO
    {
      flag = false;
      for (int j = 1; j <= a[i][0]; j++) {
        if (!vis[a[i][j]]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        ans = false;
        break;
      }
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
}
