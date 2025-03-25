#include <queue>
#include <stdio.h>
using namespace std;
queue<int> q;
int main() {
  int n, t;
  char a[12];
  while (scanf("%d", &t) != EOF) {
    while (!q.empty()) {
      q.pop();
    }
    for (int i = 1; i <= t; i++) {
      scanf("%s", a);
      switch (a[0]) {
      case 'e':
        scanf("%d", &n);
        q.push(n);
        break;
      case 'd':
        if (!q.empty()) {
          printf("%d\n", q.front());
          q.pop();
        } else {
          printf("this is empty!\n");
        }
        break;
      case 'q':
        if (q.empty()) {
          printf("this is empty!\n");
        }
        while (!q.empty()) {
          int j = q.front();
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
