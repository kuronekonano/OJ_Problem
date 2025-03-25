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
    for (int i = 1; i <= m1; i++) /// 类型1  输入的值都为真
    {
      scanf("%d", &tmp);
      vis[tmp] = true;
    }
    for (int i = 1; i <= m2;
         i++) /// 类型2  做最终的ans判断，左边多个句型并
              /// 的结果为空集，也就是说，每行必有至少一个元素是假
    {
      scanf("%d", &a[i][0]);
      for (int j = 1; j <= a[i][0]; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    bool flag;
    for (
        int i = 1; i <= m3;
        i++) /// 类型3
             /// 由左边为真的元素并后得知右边的元素为真，可以在输入时判断每个元素的真假
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
         i++) /// 最后判断类型二中每行语句是否成立，有一句不成立则结果为NO
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
