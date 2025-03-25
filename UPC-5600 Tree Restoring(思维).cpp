#include <bits/stdc++.h> ///给出一棵树，以及每个节点离其最长距离的值，问是否可以构造出这样一棵树
using namespace std;
int main() {
  int n, a[105], vis[105];
  while (scanf("%d", &n) != EOF) {
    memset(vis, 0, sizeof(vis));
    int minn = 0x7fffffff, maxn = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < minn)
        minn = a
            [i]; /// 首先找到最长距离的最大值和最小值，最小值必定大于1/2的最大距离
      if (a[i] > maxn)
        maxn = a[i]; /// 而最长距离必定小于结点数-1
      vis[a[i]]++;
    }
    int flag = false;
    if (minn >= (maxn + 1) / 2 && maxn <= n - 1) {
      if (maxn % 2 == 1 && vis[minn] == 2 ||
          maxn % 2 == 0 &&
              vis[minn] ==
                  1) /// 判断最长距离的奇偶可以得到整棵树主干，最长线上的节点个数
      {              /// 若是奇数则最小距离必定出现2次，否则只能出现一次
        for (int i = minn; i <= maxn;
             i++) /// 从最小距离到最长节点这段距离必须都要存在
          if (vis[i] == 0) {
            printf("Impossible\n");
            flag = true;
            break;
          }
        if (!flag)
          printf("Possible\n");
      } else
        printf("Impossible\n");
    } else
      printf("Impossible\n");
  }
}
