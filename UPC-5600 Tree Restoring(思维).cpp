#include <bits/stdc++.h> ///����һ�������Լ�ÿ���ڵ�����������ֵ�����Ƿ���Թ��������һ����
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
            [i]; /// �����ҵ����������ֵ����Сֵ����Сֵ�ض�����1/2��������
      if (a[i] > maxn)
        maxn = a[i]; /// �������ض�С�ڽ����-1
      vis[a[i]]++;
    }
    int flag = false;
    if (minn >= (maxn + 1) / 2 && maxn <= n - 1) {
      if (maxn % 2 == 1 && vis[minn] == 2 ||
          maxn % 2 == 0 &&
              vis[minn] ==
                  1) /// �ж���������ż���Եõ����������ɣ�����ϵĽڵ����
      {              /// ������������С����ض�����2�Σ�����ֻ�ܳ���һ��
        for (int i = minn; i <= maxn;
             i++) /// ����С���뵽��ڵ���ξ�����붼Ҫ����
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
