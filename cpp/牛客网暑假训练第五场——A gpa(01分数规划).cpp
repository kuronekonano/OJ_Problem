#include <bits/stdc++.h> ///01分数规划
using namespace std;
const int maxn = 1e5 + 7;
const double eqs = 1e-6;
int n, k, s[maxn], c[maxn];
double mx[maxn];
bool judge(double x) /// 注意这里不等式两边的s[i]不能抵消
{
  for (int i = 0; i < n; i++)
    mx[i] = s[i] * c[i] -
            x * s[i]; /// 由题目给出不等式 Σ(s[i]*c[i])/ Σs[i] ≥ x可推出
                      /// Σ(s[i]*c[i])- x * Σs[i] ≥ 0,直接二分x的值即可
  sort(mx, mx + n);
  double ans = 0;
  for (int i = n - 1; i > k - 1; i--)
    ans += mx
        [i]; /// 排序后对于课程可选前n-k个，求和即得到不等式的求和，与0比较，大于0则x合法，试探更大的x
  return ans >= 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);
  double l = 0, r = 1e6 + 7; /// 二分范围时最大值1000*1000*100000/100000
  while (r - l > eqs)        /// 二分答案
  {
    double mid = (l + r) / 2;
    if (judge(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%f\n", l);
}
