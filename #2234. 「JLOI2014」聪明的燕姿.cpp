#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int s, pri[50000], allans[100005], half, sum, prims;
bool flag[50005];
void prim() /// O(n)素数筛
{
  prims = 0;
  memset(flag, true, sizeof(flag));
  for (int i = 2; i <= 50000;
       i++) /// 题目范围为2e9，因此最大数据的质因数不会超过sqrt(2e9)
  {
    if (flag[i])
      pri[++prims] = i;
    for (int j = 1; pri[j] * i <= 50000; j++) {
      flag[pri[j] * i] = false;
      if (i % pri[j] == 0)
        break;
    }
  }
}
bool judge(int x) /// 判断是否是质数
{
  if (x <= 50000)
    return flag[x]; /// 如果被判断数在素数表以内，可以直接返回值
  int tmp = sqrt(x);
  for (
      int i = 1; pri[i] <= tmp;
      i++) /// 如果在素数表以外，但又不超过素数表中最大值的平方，即可遍历素数表依次取模，相当于找这个被判断数的质因数
    if (x % pri[i] == 0)
      return false;
  return true;
}
void dfs(long long now, int num, int ans) {
  if (now == 1) {
    allans[sum++] = ans;
    return;
  }
  if (now - 1 >= pri[num] && judge(now - 1))
    allans[sum++] = ans * (now - 1);
  for (int i = num; pri[i] * pri[i] <= now; i++) {
    int add = pri[i], tp = 1 + pri[i];
    while (tp <= now) {
      if (now % tp == 0)
        dfs(now / tp, i + 1, ans * add);
      add = add * pri[i];
      tp += add;
    }
  }
}
int main() {
  prim();
  while (scanf("%d", &s) != EOF) {
    sum = 0, half = sqrt(s);
    dfs(s, 1, 1);
    printf("%d\n", sum);
    sort(allans, allans + sum);
    for (int i = 0; i < sum; i++)
      printf("%d%c", allans[i], i == sum - 1 ? '\n' : ' ');
  }
}
