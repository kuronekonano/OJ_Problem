#include <bits/stdc++.h> ///大于等于水密度的直接完全浸没水中
#define LL                                                                     \
  long long /// 否则计算其质量，等于排开水的质量，同时水的密度是1，等于排开水的体积
#define M(a, b)                                                                \
  memset(a, b, sizeof a) /// 直接计算水增加的体积，最后比较一下是否超过桶高度即可
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1008;
int t, n;
int main() {
  double s, h, v, l, p;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", &l, &p);
      if (p >= 1.0)
        sum += l * l * l;
      else
        sum += l * l * l * p;
    }
    scanf("%lf%lf%lf", &s, &h, &v);
    sum += v;
    sum /= s;
    printf("%.2f\n", sum < h ? sum : h);
  }
}
