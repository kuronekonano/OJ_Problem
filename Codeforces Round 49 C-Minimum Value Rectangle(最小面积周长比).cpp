#include <bits/stdc++.h> ///����1e6+7���ߣ����һ�����Σ�ʹ�����ܳ��������С
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e6 + 7;
int t, n, a[maxn], b[maxn], cnt[10800];
bool vis[10800];
int main() {
  scanf("%d", &t);
  while (t--) {
    M(vis, false);
    M(cnt, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++; /// ��¼ÿ���߳��ִ���
    }
    sort(a, a + n);
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[a[i]] < 2 || vis[a[i]])
        continue; /// ��������2���ĳ�����ȥ���Ѿ���ɢ���ı���ȥ
      int sum = cnt[a[i]];
      while (sum >= 2) /// �ѱ߷ֳ�2��2��һ�飬�����ܱ�֤������Ҳ�ڼ���֮��
      {
        b[num++] = a[i];
        sum -= 2;
      }
      vis[a[i]] = true;
    }
    double ans = 100000000000;
    int aa, bb;
    for (int i = 0; i < num - 1; i++) {
      double tmp =
          4.0 * (b[i] + b[i + 1]) * (b[i] + b[i + 1]) / (1.0 * b[i + 1] * b[i]);
      if (tmp < ans) {
        ans = tmp;
        aa = b[i], bb = b[i + 1];
      }
    }
    printf("%d %d %d %d\n", aa, aa, bb, bb);
  }
}
