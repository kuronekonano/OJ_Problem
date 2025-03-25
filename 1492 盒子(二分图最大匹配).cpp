#include <stdio.h> ///����ͼ���ƥ��
#include <string.h>
int match[505];
bool edge[505][505],
    vis[505]; /// edge��ͼ����ʾ��i�Ƿ���װ��j���ӣ�vis����Ƿ�ѯ�ʹ�ĳ����
int n, k;
bool KM(int x) /// DFS������·(��ÿ���������ܶ�Ӧ��ƥ�䣬�ܱ�˭װ��ȥ)
{
  for (int i = 1; i <= n; i++) /// ������װ��x��ŵĺ���
  {
    if (!vis[i] && edge[x][i]) {
      vis[i] = true; /// ��Ƿ��ʵ�
      if (match[i] == 0 || KM(match[i])) {
        match[i] = x; /// ������Թ�ϵ
        return true;
      }
    }
  }
  return false; /// �����������е���δ�ҵ�����װ�£����������¶����
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int x, y;
    memset(edge, false, sizeof(edge));
    memset(match, 0, sizeof(match));
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &x, &y);
      edge[x][y] =
          true; /// ����x�����ܱ�y����װ�£�����ʾy�����ܱ�x����װ�£�Ҳ��������ͼ
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      memset(vis, false, sizeof(vis));
      KM(i);
    }
    for (int i = 1; i <= n; i++)
      if (match[i] == 0)
        sum++; /// ������û�б�װ�£�û����Եĺ��Ӹ���
    printf("%d\n", sum);
  }
}
