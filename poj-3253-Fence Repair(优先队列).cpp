#include <queue>   ///用了vector容器竟然不需要他的头文件？
#include <stdio.h> ///优先队列例
using namespace std;
int main() {
  int i, n;
  long long a;
  while (scanf("%d", &n) !=
         EOF) /// 注意，如果下方最右边使用了>>会报错，不能粘起来，要用空格分开
  {
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for (i = 0; i < n; i++) /// 这里用greater是从小到大的优先级，less是从大到小
    {
      scanf("%lld", &a);
      q.push(a); /// 入列
    }
    if (n == 1) {
      printf("%lld\n", q.top());
      q.pop();
      continue;
    }
    long long sum = 0, small, smaller;
    while (q.size() > 1) {
      small = q.top();
      q.pop(); /// 出列
      smaller = small + q.top(); /// 选取出列后最小的，相加，相当于两个最小的合成一堆，这里用到的是，当需要8
                                 /// 5 8三种长度时
      q.pop(); /// 取出最小的两个长度，合成一块木板，合成后的长度就是需要切割出来的长度，那么就要花费那么多
      sum =
          sum +
          smaller; /// 合成后求和加入sum中，然后再将合成后的长度塞入队列，重新排序选择最短的两组长度并合成
      q.push(
          smaller); /// 直到最终合成的是n段木板一共有的总长度，只不过合成的路径（切割费用）是两两最小的求和
    }
    printf("%lld\n", sum);
  }
  return 0;
}
