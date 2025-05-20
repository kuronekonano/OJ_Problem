#include <stdio.h> ///有n个格子线性排列，有m个攻击塔。每个塔可在L到R范围内的每个格子里造成Z点伤害。有K个怪物，每只怪物在POS处出生，并有HP的血量，问最后能活着走出N个格子的怪物有多少。
#include <string.h> ///格子数为树状数组大小，数组内存储每个格子造成的伤害，对于区间伤害不能单点更新，会超时，只能区间更新，在区间左边界L更新Z，右边界R+1更新-Z
#define LL                                                                     \
  long long /// 因此当sum函数求和时，从1到x的计数，其他区间的伤害将被边界的-Z抵消，而到达X时因为还未到达边界-Z抵消，所以将得到此处格子的伤害，即使重叠覆盖的区间也能得到伤害
int n,
    m; /// attact数组表示从格子pos处到达终点的总伤害，计算时从n倒着求到1，对于
       /// 每个POS的总伤害，由i-1加sum(i)递推而来
LL tree[100005], attact[100005];
int lowbit(int x) { return x & (-x); }
void update(int p, int x) /// 更新时从x到n
{
  while (p <= n) {
    tree[p] += x;
    p += lowbit(p);
  }
}
LL sum(int x) /// 求和时从X到1
{
  LL sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
int main() {
  int l, r, z;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    scanf("%d", &m);
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &l, &r, &z);
      update(l, z);
      update(r + 1, -z);
    }
    attact[n + 1] = 0;
    for (int i = n; i >= 1; i--)
      attact[i] = attact[i + 1] + sum(i);
    int k, pos, ans = 0;
    LL hp;
    scanf("%d", &k);
    while (
        k--) /// 最终输入每个怪物的HP和出生点时，只需比较该怪物的血量是否能承受从出生点到终点的伤害总和，即可判断该怪物是否能存活
    {
      scanf("%lld%d", &hp, &pos);
      if (hp > attact[pos])
        ans++;
    }
    printf("%d\n", ans);
  }
}
