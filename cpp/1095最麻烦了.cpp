#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
struct man {       // 又是一个结构体的应用实例！！！创建一个结构体man
  long long mark;  // 分数（对了，因为限定最大值为10的9次方，所以全部用long long
  long long money; // 金钱
  long long rp;    // 人品变量
} men[1005];       // 并且输入的最大值为1000人
int cmp(man a,
        man b) // 这是对比函数的定义，其中，函数名为cmp，定义两个变量，叫做man
               // a,man b，用a和b作比较
{
  if (a.mark == b.mark) // 若成绩相同
  {
    if (a.money == b.money) // 若金钱相同
    {
      return a.rp > b.rp; // 对比人品
    }
    return a.money > b.money; // 对比金钱
  }
  return a.mark >
         b.mark; // 对比成绩，因为是排名，所以越大的排前面，为标准的降序排列
}
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%lld%lld%lld", &men[i].mark, &men[i].money, &men[i].rp);
    }
    sort(men, men + n, cmp);
    for (i = 0; i < n; i++) {
      printf("%lld %lld %lld\n", men[i].mark, men[i].money, men[i].rp);
    }
  }
  return 0;
}
