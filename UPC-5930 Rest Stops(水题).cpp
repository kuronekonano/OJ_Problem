#include <algorithm>
#include <stdio.h> ///ÿ��������ʶȵ���Ϣվ��ֱ�ӵ��������ũ��Ȼ�����������ʶȵ���Ϣվ
#include <string.h> ///ע��ans��long long ��
using namespace std;
int n, a[105], dis[105], ans;
bool vis[105];
bool judge() {
  for (int i = 0; i < n; i++)
    if (!vis[i])
      return false;
  return true;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    ans = 0x7fffffff;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; i < n; i++)
      dis[i] = a[i] - a[i - 1];
    for (int i = 0; i < n; i++) {
      memset(vis, false, sizeof(vis));
      int cnt = 0, tmp = i;
      while (!judge()) {
        cnt++;
        //                    printf("=====%d",tmp);
        while (!vis[tmp] && tmp >= 0 && tmp < n) {
          vis[tmp] = true;
          if (dis[tmp] < dis[tmp + 1])
            tmp = tmp - 1;
          else
            tmp++;
        }
        tmp = 0;
        while (vis[tmp] && tmp < n)
          tmp++;
      }
      ans = min(ans, cnt);
    }
    printf("%d\n", ans);
  }
}
