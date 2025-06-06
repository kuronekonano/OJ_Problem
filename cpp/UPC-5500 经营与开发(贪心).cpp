#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, plant[maxn];
double dp[maxn], val[maxn], k, w, c;
int main() {
  while (scanf("%d%lf%lf%lf", &n, &k, &c, &w) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d%lf", &plant[i], &val[i]);
    k = 1 -
        0.01 *
            k; /// 钻头损失百分比，即剩余百分比，相当于每次钻探效率百分比降低到原来的一部分
    c = 1 + 0.01 * c; /// 维修百分比，即每次维修上升的效率百分比
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
      if (plant[i] == 1)
        dp[i] = max(
            dp[i + 1],
            dp[i + 1] * k +
                val[i]); /// 当前位置若钻探，得到金钱，但下一个位置的金钱因为钻头损失而变少，逆向可以得到下一个位置的金钱损失
      else
        dp[i] = max(
            dp[i + 1],
            dp[i + 1] * c -
                val[i]); /// dp[i+1]*c表示如果在此维修，那么下一个位置的金钱将变多，但仍要减去维修费用，那么这个维修费用即扣在当前位置上
    printf(
        "%.2f\n",
        dp[0] *
            w); /// 那么如果不维修，即当前直接继承上一个位置钻探得到的原有金钱
  } /// 最后结果直接乘初始能力值，即相当于之前所有获得金钱和损失金钱的w倍
}
/// 既然无法正向推导得知在每个星球是否应该钻探或是维修，那么倒着来，假设某个位置进行了钻探，获得了金钱
/// 假设某个位置进行了维修，减去了金钱，并且使得下一个星球钻探金钱变多
/// 这样逆向回来的推导选择了金钱在当前位置做什么，而继承了下一个位置的收获与代价
