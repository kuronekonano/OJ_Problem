#include <bits/stdc++.h> ///DP
using namespace std;
const int maxn = 10004;
int cnt[maxn], a[maxn], val[maxn], fa[maxn], ans[maxn];
int main() {
  int sum, n;
  while (scanf("%d%d", &sum, &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    memset(cnt, 0x3f, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    cnt[0] = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = a[i]; j <= sum; j++) /// ����ÿ����ֵ�ܵļ۸�
      {
        if (cnt[j] >=
            cnt[j - a[i]] + 1) /// ȡ�����򰴽���Ǯ�ҷ��䣬���򰴽϶�Ǯ�ҷ���
        {                      /// ������������ô��Ǯ
          cnt[j] = cnt[j - a[i]] + 1; /// �ڴ˱�Ǽ�¼
          fa[j] = j - a[i];           /// ��¼����sum��·��
          val[j] = i;                 /// ����ÿ��λ�������ĸ���ֵ�ļ�¼
        }
      }
    }
    if (cnt[sum] == cnt[sum + 3]) /// ���δ���յ�sum˵����ô���ղ���
    {
      printf("-1\n");
      continue;
    }
    while (sum) /// ������·����¼���õ���ÿ����ֵ����
    {
      ans[val[sum]]++;
      sum = fa[sum];
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  }
}
