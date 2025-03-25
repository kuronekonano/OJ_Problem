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
求 满足(a < b < c < d, h[a] < h[b] < h[d] < h[c])(简称abdc)的四元组数
转化为求 满足(a < b , h[a] < h[b], b < c, h[b] < h[c], b < d, h[b] <
h[d])(简称abxx，xx为b之后任意大于h[b]的数)的四元组数 与 满足(a < b < c < d, h[a]
< h[b] < h[c] < h[d])(简称abcd)的差 因为abxx即abcd与abdc的和

一、求abxx
即对每个b，用前面比b小的a的个数，乘后面比b大的xx的个数
树状数组预处理l_min(前面比他小的)和r_max(后面比他大的)
abxx即((∑i:1~n)l_min[i])*(r_max[i]*(r_max[i] - 1)/2)
例如 1 2 6 5 4 3
对b = 2，有a = 1，r_max[i] = 4, xx = {{6,5},{6.4},{6,3},{5,4},{5,3},{4,3}}, 共 4
* 3 / 2 = 6 个

二、求abcd
即对每个c，用前面比c小的ab对数，乘后面比c大的d的个数
前面比c小的ab对数，即前面比c小的b的l_min[b]之和
因为l_min[b]即前面比b小的a的个数，即ab对数，(∑i:1~(c -
1))l_min[i]即前面比c小的ab对数 例如 1 2 3 4 5 对c = 5，有ab = {{1,2}(l_min[2] =
1),{1,3},{2,3}(l_min[3] = 2),{1,4},{2,4},{3,4}(l_min[4] = 3)} (∑i:1~(c -
1))l_min[i] = l_min[1] + l_min[2] + l_min[3] + l_min[4] = 0 + 1 + 2 + 3 = 6
abcd即((∑i:1~(c - 1))l_min[i])*r_max[i]
从前往后遍历，累加l_min[i]，ask[c - 1]即为(∑i:1~(c - 1))l_min[i]

**/
