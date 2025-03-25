#include <stack>
#include <stdio.h> ///栈进出判断小应用
using namespace std;
int main() {
  int n, i, a[55];
  while (scanf("%d", &n) != EOF) {
    stack<int> q;
    while (!q.empty()) /// 清空栈
    {
      q.pop();
    }
    for (i = 0; i < n; i++) /// 输入
    {
      scanf("%d", &a[i]);
    }
    int j = 0;
    for (i = 1; i <= n; i++) /// 判断进出是否合理的循环
    {
      q.push(i);
      while (!q.empty() && q.top() == a[j]) {
        q.pop();
        j++;
      }
    }
    if (j == n) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
