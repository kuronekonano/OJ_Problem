#include <algorithm>
#include <stdio.h>
using namespace std;
struct day {
  int x, y;
} xa[108], ya[109];
int main() {
  int t, i, j, m, n, xn, yn;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &m, &xn, &yn);
    for (i = 1; i <= xn; i++) {
      scanf("%d%d", &xa[i].x, &xa[i].y);
    }
    for (i = 1; i <= yn; i++) {
      scanf("%d%d", &ya[i].x, &ya[i].y);
    }
    int ans = 0;
    for (i = 1; i <= xn; i++) {
      for (j = 1; j <= yn; j++) {
        int maxn = max(xa[i].x, ya[j].x);
        int minn = min(xa[i].y, ya[j].y);
        if (minn - maxn + 1 < m)
          continue;
        ;
        ans =
            ans +
            (minn - maxn + 2 -
             m); /// minn-maxn=���������ʵ�ʾ�������=�������+1������Ѻõ���=ʵ�ʾ�������-m(��õ�������)+1(ǰm�챻��ȥ��������m���õ�1������)
      } /// ��ȥm���õ�1��������ʣ����������ÿ����1���������������Ϊminn-maxn+1-m+1
    }
    printf("%d\n", ans);
  }
  return 0;
}
