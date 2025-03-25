#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, k, a, b;
  while (scanf("%d%d%d%d", &n, &k, &a, &b) != EOF) {
    if ((a == 0 || b == 0) && n > k) {
      printf("NO\n");
      continue;
    }
    int judge = max(a, b) % (min(a, b) + 1);
    if (judge == 0 && max(a, b) / (min(a, b) + 1) > k) {
      printf("NO\n");
      continue;
    }
    if (judge != 0 && max(a, b) / (min(a, b) + 1) >= k) {
      printf("NO\n");
      continue;
    }
    int flag = 0, num = 0, ei = 0;
    while (num != n) {
      if (a > b) {
        if (ei == 1)
          flag++;
        while (flag != k && num != n) {
          printf("G");
          ei = 1;
          a--;
          flag++;
          num++;
          if (a == 0)
            break;
        }
        flag = 0;
        if (num != n && b != 0) {
          printf("B");
          ei = -1;
          b--;
          num++;
        }
      } else if (a < b) {
        if (ei == -1) {
          flag++;
        }
        while (flag != k && num != n) {
          printf("B");
          ei = -1;
          b--;
          num++;
          flag++;
          if (b == 0)
            break;
        }
        flag = 0;
        if (num != n && a != 0) {
          printf("G");
          ei = 1;
          a--;
          num++;
        }
      } else if (a == b) {
        if (ei == 0)
          ei = -1;
        break;
      }
    }
    while (num != n) {
      if (ei == 1) {
        printf("B");
        b--;
        num++;
        ei = -1;
      } else if (ei == -1) {
        printf("G");
        a--;
        num++;
        ei = 1;
      }
    }
    printf("\n");
  }
}
