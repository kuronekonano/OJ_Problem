#include <stdio.h>
#include <stdlib.h>
int main() {
  int t, n, i, x[108], y[108];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d%d", &x[i], &y[i]);
    }
    if (n != 4) {
      printf("NO\n");
      continue;
    }
    long long dis = 0, minn = 0x7fffffff, tmi = 0;
    for (i = 1; i < n; i++) {
      dis = (x[0] - x[i]) * (x[0] - x[i]) + (y[0] - y[i]) * (y[0] - y[i]);
      if (dis < minn) {
        minn = dis;
        tmi = i;
      }
    }
    int dy = x[0] - x[tmi], dx = y[0] - y[tmi];
    bool flag = false;
    for (i = 1; i < n; i++) {
      if (i != tmi)
        for (int j = 1; j < n;
             j++) /// 记得判断条件，是加dx与减dy和减dx加dy同时存在
        {
          if ((x[tmi] - dx == x[i] && x[0] - dx == x[j] &&
               y[tmi] + dy == y[i] && y[0] + dy == y[j]) ||
              (x[tmi] - dx == x[i] && x[0] - dx == x[j] &&
               y[tmi] + dy == y[i] && y[0] + dy == y[j]) ||

              (x[tmi] + dx == x[j] && x[0] + dx == x[i] &&
               y[tmi] - dy == y[j] && y[0] - dy == y[i]) ||
              (x[tmi] + dx == x[j] && x[0] - dx == x[i] &&
               y[tmi] - dy == y[j] && y[0] + dy == y[i])) {
            flag = true;
          }
        }
    }
    printf("%s\n", flag ? "YES" : "NO");
  }
}
