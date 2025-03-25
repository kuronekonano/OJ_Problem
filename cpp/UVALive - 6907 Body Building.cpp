#include <stdio.h>
#include <string.h>
bool ma[108][108], vis[105], dvis[105], nvis[105];
int n, m, edge = 0, node = 0, inout[105];
void dfs(int i) {
  node++; /// ������������ѣ���¼������ѵĽڵ㣬��������ͨͼ��һ����
  vis[i] = dvis[i] = true;
  for (int j = 1; j <= n; j++)
    if (ma[i][j] && !vis[j])
      dfs(j);
}
void nfs(int i) {
  node++;
  nvis[i] = true;
  for (int j = 1; j <= n; j++)
    if (ma[i][j] && !nvis[j])
      nfs(j);
}
int main() {
  int t, cas = 0;
  scanf("%d", &t);
  while (t--) {
    memset(vis, false, sizeof(vis));
    memset(ma, false, sizeof(ma));
    memset(inout, 0, sizeof(inout));
    int x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      ma[x][y] = ma[y][x] = true;
      inout[x]++;
      inout[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        node = 0;
        edge = 0;
        memset(dvis, false, sizeof(dvis));
        dfs(i);                      /// ��һ����ͨͼ�����нڵ㣬�����
        for (int j = 1; j <= n; j++) /// �ڱ�ǵĽڵ��н��нڵ���������
          if (dvis[j])
            for (int k = 1; k <= n; k++)
              if (ma[j][k])
                edge++; /// �����б���ǵĵ㣬��Ϊ�����ͨͼ��һ���֣���¼��Щ�����ɵıߵ�����
        edge /= 2;
        if (node & 1)
          continue;
        if (edge ==
            (node / 2) * (node / 2 - 1) +
                1) /// �������n���㣬��ô����((n/2-1)*n)/2���ߵ���ȫͼ�����ｫnode����ֳ����ݣ���˹���node/2*(node/2-1)���ߣ�������������������һ����
        {
          int out[2] = {0, 0},
              num = 0; /// �������λ��Ҫ��ʼ�����������������룡��
          for (int j = 1; j <= n; j++) {
            if (dvis[j] && inout[j] == node / 2) /// ���ڵ�ǰ������С��ͨͼ��
            {
              out[num++] = j;
            }
          }
          ma[out[0]][out[1]] = ma[out[1]][out[0]] = false;
          node = 0;
          memset(nvis, false, sizeof(nvis));
          nfs(out[0]);
          if (node == inout[out[0]])
            ans++;
        }
      }
    }
    printf("Case #%d: %d\n", ++cas, ans);
  }
}
