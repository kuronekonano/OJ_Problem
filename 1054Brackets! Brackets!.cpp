#include <stack>
#include <stdio.h> //完全照搬 基础数据结构——栈 的代码
#include <string.h>
using namespace std;
int main() {
  char a[109];
  int i, n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    stack<char> q;
    while (!q.empty()) {
      q.pop();
    }
    n = strlen(a);
    bool flag = true;
    for (i = 0; i < n; i++) {
      if (a[i] == '{' || a[i] == '}' || a[i] == '(' || a[i] == ')' ||
          a[i] == '[' || a[i] == ']') {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
          q.push(a[i]);
          continue;
        } else if (a[i] == ')' && !q.empty() && q.top() == '(') {
          q.pop();
        } else if (a[i] == ']' && !q.empty() && q.top() == '[') {
          q.pop();
        } else if (a[i] == '}' && !q.empty() && q.top() == '{') {
          q.pop();
        } else {
          flag = false;
          break;
        }
      }
    }
    if (!q.empty() || flag == false) {
      printf("Invalid\n");
    } else {
      printf("Valid\n");
    }
  }
  return 0;
}
