#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 5e5 + 7;
int a[maxn], tmp[maxn];
int n;
LL ans;
void Meg(int l, int mid, int r) {
  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (a[i] < a[j])
      tmp[k++] = a[i++];
    else {
      ans += mid - i + 1; /// 逆序数计数
      tmp[k++] = a[j++];
    }
  }
  while (i <= mid)
    tmp[k++] = a[i++];
  while (j <= r)
    tmp[k++] = a[j++];
  for (int i = l, k = 0; i <= r; k++, i++)
    a[i] = tmp[k];
}
void Msort(int l, int r) /// 归并排序模板
{
  if (l < r) {
    int mid = (l + r) >> 1;
    Msort(l, mid);
    Msort(mid + 1, r);
    Meg(l, mid, r);
  }
}
int main() {
  while (scanf("%d", &n) && n) {
    ans = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    Msort(1, n);
    printf("%lld\n", ans);
  }
}
