#include <bits/stdc++.h>
using namespace std;
struct node {
  int i, val;
} a[100005];
bool cmp(node a, node b) { return a.val < b.val; }
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].val);
      a[i].i = i;
    }
    int sum = 0;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
      if (abs(a[i].i - i) % 2 == 1)
        sum++;
    printf("%d\n", sum / 2);
  }
}
