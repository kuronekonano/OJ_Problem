#include <stdio.h> ///���Ա�������δ���ɵ���������ڣ��ҵ�һ������������ڵ������Ͻ�Ҫ����Ľڵ���߾����һ�����ֵ����
int main() {
  int n, a[30008];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    int ans = 0, dis = a[0], i = 0;
    while (i < n - 1) {
      int maxn = 0, ii = 0;
      while (dis--) {
        i++;
        if (i >= n - 1)
          break;
        if (i - ii + a[i] > maxn)
          maxn = a[i], ii = i;
      }
      ans++;
      if (i >= n - 1)
        break;
      dis = maxn, i = ii;
    }
    printf("%d\n", ans);
  }
}
