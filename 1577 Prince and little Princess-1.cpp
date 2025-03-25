#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int n, i, j, temp;
  while (scanf("%d", &n) != EOF) {
    stack<int> q;
    for (i = 0; i < n; i++) {
      scanf("%d", &temp);
      q.push(temp);
    }
    char com[10];
    while (scanf("%s", com)) {
      if (strcmp(com, "push") == 0) {
        scanf("%d", &temp);
        q.push(temp);
      } else if (strcmp(com, "pop") == 0) {
        q.pop();
      } else if (strcmp(com, "top") == 0) {
        printf("%d\n", q.top());
      } else if (strcmp(com, "empty") == 0) {
        printf("%s\n", q.empty() ? "T^T" : "^_^");
      } else {
        break;
      }
    }
  }
}
