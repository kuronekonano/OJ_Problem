#include <algorithm> //贪心
#include <stdio.h>
using namespace std;
struct tv // 定义结构体存储的是每个节目的开始时间和结束时间
{
  int s;
  int t;
} time[105];
bool cmp(tv a, tv b) // 排序的是电视节目的结束时间
{
  return a.t < b.t; // 谁先结束就看哪个节目
}
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) // n个节目
  {
    if (n == 0) {
      return 0;
    }
    for (i = 0; i < n; i++) // 每个节目的开始时间与结束时间
    {
      scanf("%d%d", &time[i].s, &time[i].t);
    }
    sort(time, time + n, cmp); // 排序结束时间
    int sum = 0;               // 可看节目总数计数器
    int last = 0;
    for (i = 0; i < n; i++) // 遍历排序好后节目的开始结束时间
    {
      if (i == 0) {
        sum = 1;          // 第一个节目肯定是能看的
        last = time[i].t; // 把开始时间调整为当前观看节目的结束时间
      } else {
        if (time[i].s >= last) // 若开始时间大于等于上一个结束时间
        {
          last = time[i].t; // 就看这个节目
          sum++;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
