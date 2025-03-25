#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 16777216;
int tre[maxn];
int n, a[maxn];
LL lmin[maxn], rmax[maxn];
void updata(int pos, int val) {
  for (int i = pos; i <= n; i += i & -i)
    tre[i] += val;
}
int query(int pos) {
  int ans = 0;
  for (int i = pos; i; i -= i & -i)
    ans += tre[i] % mod;
  return ans % mod;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(tre, 0, sizeof tre);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      int tmp = query(a[i]);
      lmin[i] = tmp;
      updata(a[i], 1);
    }
    LL abxx = 0, abcd = 0;
    memset(tre, 0, sizeof tre);
    for (int i = n - 1; i >= 0; i--)
      rmax[i] = n - i - 1 - query(a[i]), updata(a[i], 1);
    memset(tre, 0, sizeof tre);
    for (int i = 1; i < n - 2; i++)
      abxx += (lmin[i] * rmax[i] * (rmax[i] - 1) / 2) % mod;
    for (int i = 0; i < n - 1; i++)
      abcd = (abcd + (query(a[i] - 1) * rmax[i]) % mod) % mod,
      updata(a[i], lmin[i]);
    //        printf("%lld %lld\n",abxx,abcd);
    printf("%lld\n", (abxx - abcd + mod) % mod);
  }
  return 0;
}
/**
�� ����(a < b < c < d, h[a] < h[b] < h[d] < h[c])(���abdc)����Ԫ����
ת��Ϊ�� ����(a < b , h[a] < h[b], b < c, h[b] < h[c], b < d, h[b] <
h[d])(���abxx��xxΪb֮���������h[b]����)����Ԫ���� �� ����(a < b < c < d, h[a]
< h[b] < h[c] < h[d])(���abcd)�Ĳ� ��Ϊabxx��abcd��abdc�ĺ�

һ����abxx
����ÿ��b����ǰ���bС��a�ĸ������˺����b���xx�ĸ���
��״����Ԥ����l_min(ǰ�����С��)��r_max(����������)
abxx��((��i:1~n)l_min[i])*(r_max[i]*(r_max[i] - 1)/2)
���� 1 2 6 5 4 3
��b = 2����a = 1��r_max[i] = 4, xx = {{6,5},{6.4},{6,3},{5,4},{5,3},{4,3}}, �� 4
* 3 / 2 = 6 ��

������abcd
����ÿ��c����ǰ���cС��ab�������˺����c���d�ĸ���
ǰ���cС��ab��������ǰ���cС��b��l_min[b]֮��
��Ϊl_min[b]��ǰ���bС��a�ĸ�������ab������(��i:1~(c -
1))l_min[i]��ǰ���cС��ab���� ���� 1 2 3 4 5 ��c = 5����ab = {{1,2}(l_min[2] =
1),{1,3},{2,3}(l_min[3] = 2),{1,4},{2,4},{3,4}(l_min[4] = 3)} (��i:1~(c -
1))l_min[i] = l_min[1] + l_min[2] + l_min[3] + l_min[4] = 0 + 1 + 2 + 3 = 6
abcd��((��i:1~(c - 1))l_min[i])*r_max[i]
��ǰ����������ۼ�l_min[i]��ask[c - 1]��Ϊ(��i:1~(c - 1))l_min[i]

**/
