#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, m, l, i, r;
  while (scanf("%d%d", &n, &m) != EOF) /// ����С����
  {
    int ans = 0x7fffffff;
    for (i = 0; i < m; i++) {
      scanf("%d%d", &l, &r);
      ans = min(ans, r - l + 1);
    }
    printf("%d\n", ans);
    for (i = 0; i < n; i++) {
      printf(
          "%d%c", i % ans,
          i == n - 1
              ? '\n'
              : ' '); /// Ĭ��Ϊ������������Сֵ����ͬ��Ҳ����˵����0��ʼһֱ����С����ĳ��ȣ�Ȼ���ִ�0��ʼ
    }
  }
  return 0;
}
