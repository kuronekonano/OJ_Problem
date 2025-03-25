#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[1000006];
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    stack<char> q;
    while (!q.empty()) {
      q.pop();
    }
    scanf("%s", a);
    int n = strlen(a);
    int flag = 0;
    for (i = 0; i < n; i++) // 遍历字符串
    {
      if (a[i] == '(') {
        q.push(a[i]); // 遇到左括号入栈
        continue;
      } else if (
          a[i] == ')' && !q.empty() &&
          q.top() ==
              '(') // 遇到右括号且非空，且栈顶为左括号时，可以与左括号相互匹配，计数器加一
      {
        q.pop(); // 并使当前左括号出栈
        flag++;
      }
    }
    printf("%d\n", flag * 2); // 括号匹配成功时字符数量总是二的倍数
  }
  return 0;
}
