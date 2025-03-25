#include <stack>
#include <stdio.h> ///记录路径的进出
#include <string.h>
using namespace std;

int main() {
  int n, i;
  char a[10], b[10];
  while (scanf("%d", &n) != EOF) {
    stack<char> q;
    while (!q.empty()) {
      q.pop();
    }
    scanf("%s", a); /// 输入部分  入栈顺序
    scanf("%s", b); /// 出栈顺序
    int sum = 0;
    int j = 0, k = 0; /// k0时一定是in不能out，所以后面++跳过
    bool flag[10];
    memset(flag, false, sizeof(flag));
    for (i = 0; i < n; i++) /// 遍历入栈字符串
    {
      q.push(a[i]); /// 一个一个字符入栈，入一个，再判断出不出，不出继续入
      k++;          /// 用于记录路径而计数
      while (!q.empty() &&
             q.top() == b[j]) /// 一直拿栈顶比较，直到找到出栈顺序中的首项
      {
        q.pop();          /// 能出先出
        flag[k++] = true; /// 标记TRUE的都是可以出栈的，也就是Out
        j++;              /// 出完了出栈队列中的一个，往下找下一个
      }
    }
    if (j ==
        n) /// 上一个循环能完整进行，也就是j和i（n）增长到相同数值，说明出栈队列全部可出，yes条件达成
    {
      printf("Yes.\n");
      for (i = 0; i < k; i++) /// 输出步骤
      {
        if (flag[i]) {
          printf("out\n");
        } else {
          printf("in\n");
        }
      }
    } else {
      printf("No.\n");
    }
    printf("FINISH\n");
  }
  return 0;
}
