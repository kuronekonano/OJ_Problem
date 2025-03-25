#include <algorithm>
#include <stdio.h>   ///01分数规划
using namespace std; /// 题目要求Σ ai / Σ bi 值最大，那么有不等式 Σ ai / Σ
                     /// bi ≥ x 即这个最大值x是所求
const int maxn =
    1e3 +
    8; /// 不等式可以化为   Σ ai ≥ Σ bi *x  ---->   Σ ai - Σ bi *x ≥0
       /// 那么计算Σ ai - Σ bi *x 的值 判断求和前n-k个结果是否大于等于0,
const double eqs =
    1e-6; /// 大于等于0表示符合条件，我们向后二分更大的x，即二分答案，也就是正确删除k个的情况下获得更大的x
int a[maxn],
    b[maxn]; /// 否则若求和结果小于0，说明不等式不成立，选择的最大值太大，ai无法满足
double mx[maxn];
int n, k;
bool judge(double x) /// 二分最大值
{
  for (int i = 1; i <= n; i++)
    mx[i] = a[i] - x * b[i];
  sort(mx + 1, mx + 1 + n);
  double ans = 0;
  for (int i = n; i > k; i--)
    ans += mx[i]; /// 取前n-k个最大值算出来的数
  return ans >= 0;
}
int main() {
  while (scanf("%d%d", &n, &k) && (n || k)) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
      scanf("%d", &b[i]);
    double l = 0, r = 1;
    while (r - l > eqs) {
      double mid = (l + r) / 2;
      if (judge(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.0f\n", l * 100);
  }
}
