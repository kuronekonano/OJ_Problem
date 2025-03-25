#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn], ny, nx;
int n, a[maxn][4], b[maxn][4];
int linker[maxn], lx[maxn], ly[maxn]; /// y�и���ƥ��״̬��x,y�еĵ���
int slack[maxn];
bool visx[maxn], visy[maxn];
bool DFS(int x) {
  visx[x] = true;              /// ���ѯ�ʹ�
  for (int y = 0; y < ny; y++) /// ��ѯһ��x��ƥ�������y
  {
    if (visy[y])
      continue; /// �Ѿ���ǹ��Ĳ����ٲ�ѯ
    int tmp = lx[x] + ly[y] - g[x][y];
    if (tmp == 0) /// ��Ȳ���ƥ��
    {
      visy[y] = true;
      if (linker[y] == -1 ||
          DFS(linker[y])) /// �ж�y���Ƿ�ƥ��������Ƿ�y���ƥ�����ҵ�����·
      {
        linker[y] = x; /// y��ƥ��x��
        return true;   /// ����·���ҳɹ�
      }
    } else if (slack[y] > tmp) /// ����ʧ�ܣ����¼�¼��С����y���dֵ
      slack[y] = tmp;
  }
  return false;
}
int KM() {
  memset(linker, -1, sizeof(linker));
  memset(ly, 0, sizeof(ly));
  for (int i = 0; i < nx; i++) {
    lx[i] = -INF;
    for (int j = 0; j < ny; j++)
      if (g[i][j] > lx[i])
        lx[i] = g[i][j];
  }
  for (int x = 0; x < nx; x++) {
    for (int i = 0; i < ny; i++)
      slack[i] = INF;
    while (true) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if (DFS(x))
        break; /// �ҵ�����·
      int d = INF;
      for (int i = 0; i < ny; i++) /// ��ʣ��δƥ���y�ڵ�
        if (!visy[i] && d > slack[i])
          d = slack[i];
      for (int i = 0; i < nx; i++)
        if (visx[i])
          lx[i] -= d;
      for (int i = 0; i < ny; i++) {
        if (visy[i])
          ly[i] += d;
        else
          slack[i] -= d;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < ny; i++)
    if (linker[i] != -1)
      res += g[linker[i]][i];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++)
      scanf("%d", &b[i][j]);
    for (int j = 0; j < n; j++) {
      int val = 0;
      for (int k = 0; k < 4;
           k++) /// �����Ҽ�һ������������������Ϊ�Ƚϵ���������֮���Ȩֵ
      {
        if (b[i][k] == a[j][0])
          val++;
        if (b[i][k] == a[j][1])
          val++;
        if (b[i][k] == a[j][2])
          val++;
        if (b[i][k] == a[j][3])
          val++;
      }
      g[i][j] = val; /// Ҫ��֤�ߵ������ټ���������࣬��ô�������Ȩֵƥ������
    }
  }
  nx = ny = n;
  int sum = KM();
  int ans = n * 4 - sum;
  printf("%d\n", ans);
}
