#include <stack>
#include <stdio.h>
using namespace std;
stack<int> q;
int main() {
  int t, i, n;
  char a[10];
  while (scanf("%d", &t) != EOF) {
    while (!q.empty()) {
      q.pop();
    }
    for (i = 1; i <= t; i++) {
      scanf("%s", a);
      switch (a[2]) {
      case 's':
        scanf("%d", &n);
        q.push(n);
        break;
      case 'p':
        if (!q.empty()) {
          printf("%d\n", q.top());
          q.pop();
        } else {
          printf("this is empty!\n");
        }
        break;
      case 'e':
        if (q.empty()) {
          printf("this is empty!\n");
        }
        while (!q.empty()) {
          int j = q.top();
          q.pop();
          printf("%d\n", j);
        }
        break;
      }
    }
    printf("\n");
  }
  return 0;
}
