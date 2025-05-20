#include <algorithm>
#include <stdio.h> ///简单贪心
using namespace std;
struct stone {
  int x, y, v;
  long long dis;
} a[1008];
bool cmp(stone a, stone b) {
  if (a.dis == b.dis) {
    return a.v > b.v; /// 若距离相同。按体积大小排序(体积大靠前)
  }
  return a.dis < b.dis; /// 首先按石子到瓶的距离排序(距离短靠前)
}
int main() {
  int n, m, b, i;
  while (scanf("%d%d%d", &n, &m, &b) != EOF) {
    int sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
      a[i].dis = a[i].x * a[i].x + a[i].y * a[i].y; /// 两点间距离，没开方
      sum += a[i].v;
    }
    if (sum + b < m) /// 若所有石头体积加上水的体积小于瓶的体积，则不可能过喝到
    {
      printf("-1\n");
      continue;
    }
    sort(a, a + n, cmp); /// 石子选择顺序排序
    sum = b;             /// 初始值为水的体积
    i = 0;
    int flag = 0; /// 石子数量计数
    while (sum < m && i <= n) {
      sum += a[i++].v; /// 体积求和
      flag++;
    }
    printf("%d\n", flag);
  }
}
