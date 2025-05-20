#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
int main() {
  int i, n, a[105];
  while (scanf("%d", &n) != EOF) {
    stack<int> s; // 定义一个int型的栈，名为s
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]); // 开始循环输入数字，并按顺序存入数组
    }
    int j = 1;               // 初始化j
    for (i = 1; i <= n; i++) // 遍历数组
    {
      s.push(i); // 从1到n检阅数字
      while (!s.empty() &&
             s.top() ==
                 a[j]) // 按顺序入栈，判断若是空栈，且栈顶等于输入的第一个数
      {
        s.pop(); // 出栈
        j++; // 计数器，按顺序出栈，不按顺序会出现栈不为空，或计数器与输入数字不符的情况
      }
    }
    if (j == n + 1) // j的数量最后会多加1，比对时应是n+1
    {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
