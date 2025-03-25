#include <stdio.h>
int people[1000000];
int find(int a) {
  int r = a, t;
  while (r != people[r]) {
    t = r;
    r = people[r];
    people[t] = people[r];
  }
  return r;
}
void join(int x, int y) {
  int fa = find(x), fb = find(y);
  if (fa != fb) {
    people[fa] = fb;
  }
}
int main() {
  int m, n, i, j, x, y;
  while (scanf("%d%d", &m, &n) != EOF) {
    for (i = 1; i <= m; i++) {
      people[i] = i;
    }
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &x, &y);
      join(x, y);
    }
    int q, a, b;
    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
      scanf("%d%d", &a, &b);
      if (find(a) == find(b)) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }
  return 0;
}
