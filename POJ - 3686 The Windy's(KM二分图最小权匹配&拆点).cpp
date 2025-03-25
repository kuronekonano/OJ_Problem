/**�������ͼ����Сƥ�䡿
ֻ���Ȩֵȡ������Ϊ���ģ�����KM������Ȩƥ�䣬ȡ����Ϊ����СȨƥ�䡣
**/
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;
int nx, ny;                            /// ���ߵĵ���
int g[N][N * 50];                      /// ����ͼ����
int linker[N * 50], lx[N], ly[N * 50]; /// y�и���ƥ��״̬��x,y�еĵ���
int slack[N * 50];
bool visx[N], visy[N * 50];
bool DFS(int x) {
  visx[x] = true;               /// ���ѯ�ʹ�
  for (int y = 1; y <= ny; y++) /// ��ѯһ��x��ƥ�������y
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
  memset(ly, 0, sizeof(ly)); /// ��ʼ���ҽڵ�Ȩֵ����ʼ����0
  for (int i = 1; i <= nx; i++) {
    lx[i] = -INF;
    for (int j = 1; j <= ny; j++)
      if (g[i][j] > lx[i]) /// lx[i]ȡ����Ȩ
        lx[i] = g[i][j];
  }
  for (int x = 1; x <= nx; x++) /// ƥ��n���ڵ�
  {
    for (int i = 0; i <= ny; i++)
      slack[i] = INF;
    while (true) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if (DFS(x))
        break; /// �ҵ�����·
      int d = INF;
      for (int i = 1; i <= ny; i++) /// ��ʣ��δƥ���y�ڵ�
        if (!visy[i] && d > slack[i])
          d = slack[i];
      for (int i = 1; i <= nx; i++)
        if (visx[i])
          lx[i] -= d;
      for (int i = 1; i <= ny; i++) {
        if (visy[i])
          ly[i] += d;
        else
          slack[i] -= d;
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= ny; i++)
    if (linker[i] != -1)
      res += g[linker[i]][i];
  return res;
}
int main() {
  int n, m, t;
  scanf("%d", &t);
  while (t--) {
    int tmp;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &tmp);
        for (int k = 1; k <= n; k++)
          g[i][(j - 1) * n + k] = -tmp * k;
      }
    nx = n, ny = n * m;
    double sum = -KM();
    printf("%f\n", sum / n);
  }
}
