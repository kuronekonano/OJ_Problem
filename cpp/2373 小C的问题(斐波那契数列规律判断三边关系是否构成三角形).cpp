#include <algorithm> ///首先对于三角形三边规律，两边之和必大于第三边，因此理论上我们只要找到两个较短边求和后与最长边比较即可
#include <stdio.h> ///给出一段序列，在序列中选择一一段区间，在区间中任选3个值作为三条边，判断是否能构成三角形
#define LL                                                                     \
  long long /// 由于数列是乱序的，数列中每个值小于1e18，数列长度和区间询问次数都是1e5，不可能暴力查询
using namespace std; /// 此处想到，因为两边之和一定要大于第三边，因此当数列满足，排序后，较小两边相加都小于等于下一条边，这种序列即斐波那契数列，甚至比斐波那契数列更容易增大的数列
struct
    node /// 反过来想想，既然构造一个超长的不能满足构成三角形的数列必须最低限度是构造一个斐波那契数列，那么这个数列长度能否构造得很长？不行，因为斐波那契数列到第100个就超过1e10了
{ /// 因为数列中所有值都小于1e18，因此任何区间大于100的长度，必定存在能构造出三角形的三边，100以内的，直接区间排序后暴力查找是否存在能构成三边的三角形即可
  LL v;
  int id;
} a[100005];
bool cmp(node a, node b) { return a.v < b.v; }
bool cmpid(node a, node b) { return a.id < b.id; }
int main() {
  int n, m, l, r;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i].v), a[i].id = i;
    scanf("%d", &m);
    while (m--) {
      scanf("%d%d", &l, &r);
      l--;
      r--;
      if (r - l + 1 >= 100) {
        printf("Yes\n");
        continue;
      } else {
        bool flag = false;
        sort(a + l, a + r + 1, cmp);
        for (int i = l; i <= r - 2; i++) {
          if (a[i].v + a[i + 1].v > a[i + 2].v) {
            flag = true;
            printf("Yes\n");
            break;
          }
        }
        if (!flag)
          printf("No\n");
        sort(a + l, a + r + 1, cmpid);
      }
    }
  }
}
