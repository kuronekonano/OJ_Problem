#include <stdio.h>  ///����ͼ���ƥ��   ��С�㸲����=���ƥ����
#include <string.h> ///���к���ת���ɵ㣬ÿ����ת��Ϊ�������ߵ��ߣ�����һ������ͼ��Ҫ����С������������������еı�(������ɱߵĵ�)������С�ĵ�(������ɵ������)������ʵ��
int match[505];     ///
bool edge[505][505],
    vis[505]; /// edge��ͼ����ʾ�ڵ�i��j���Ƿ��е���ڣ�vis����Ƿ�ѯ�ʹ�ĳ����
int n, k;
bool KM(int x) /// DFS������·
{
  for (int i = 1; i <= n; i++) /// ��������õ���Եĵ�
  {
    if (!vis[i] && edge[x][i]) {
      vis[i] = true; /// ��Ƿ��ʵ�
      if (match[i] == 0 || KM(match[i])) {
        match[i] = x; /// ������Թ�ϵ
        return true;
      }
    }
  }
  return false; /// �����������е�
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int x, y;
    memset(edge, false, sizeof(edge));
    memset(match, 0, sizeof(match));
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &x, &y);
      edge[x][y] =
          true; /// �����к����ǲ�ͬ�ģ���һ����Ե����к͵�������Ե�һ���������㣬���������ͼ
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      memset(vis, false, sizeof(vis));
      if (KM(i))
        sum++; /// ����·��������������ƥ������
    }
    printf("%d\n", sum);
  }
}
